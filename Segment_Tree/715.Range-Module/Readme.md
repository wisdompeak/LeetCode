### 715.Range-Module

#### 解法1：使用有序map

对于这种interval类型的题目，我们选用ordered_map，将左边界作为key，右边界作为val，则所有的interval都按左边界从小到大排序。

加入一个interval时，要考虑这么几点：

1. 新加入的区间是否和左边的某个区间部分重合？是的话，那么左边的那个区间就要拉长、重新赋值其右边界；如果不是，那么left就是一个新的左边界。
2. 新加入的区间是否和右边的某个区间部分重合？是的话，那么右边的那个区间就要删除它的key，其右边界将作为一个新区间的右边界。
3. 新加入的区间范围内的任何key都是需要抹去的。
4. 新建立一个区间。

代码如下：
```cpp
int leftBound = left;
auto pos1=Map.lower_bound(left);
if (pos1!=Map.begin() && prev(pos1,1)->second >= left)  //左边界部分重合
    leftBound = prev(pos1,1)->first;
    
int rightBound = right;
auto pos2=Map.upper_bound(right);
if (pos2!=Map.begin() && prev(pos2,1)->first <= right)  //右边界部分重合
    rightBound = max(right, prev(pos2,1)->second);
    
Map.erase(pos1,pos2) // 删除一个前闭后开的迭代器区间
Map[leftBound]=rightBound;
```

删除一个interval时，要考虑这么几点：

1. 要删除的区间是否和左边的某个区间部分重合？是的话，那么左边的那个区间就要缩短，重新赋值其右边界。
2. 要删除的区间是否和右边的某个区间部分重合？是的话，那么右边的那个区间就要缩短，重新定义其左边界。
3. 要删除的区间范围内的任何key都是需要抹去的。

代码如下：
```cpp
auto pos1=Map.lower_bound(left);
bool flag1=0;
if (pos1!=Map.begin() && prev(pos1,1)->second >= left)
{
    flag1=1;
    temp1=prev(pos1,1)->second;
}

auto pos2=Map.lower_bound(right);
bool flag=0;
int temp2;
if (pos2!=Map.begin() && prev(pos2,1)->second > right)
{
    flag2=1;
    temp2=prev(pos2,1)->second;
}

Map.erase(pos1,pos2);
if (flag1) Map[temp1]=left;
if (flag2) Map[right]=temp2;
```
特别注意，对于迭代器的修改操作，得安排在删除操作之后进行。


#### 解法2：使用线段树

此题适合标准的线段树模型和数据结构。从难度上将，本题是基于307和370基础上的更进一步，因为我们需要再设计一个remove的操作。

在segTree类中，按照常规的操作，需要有如下成员变量
```
int begin, end;
bool status;
segTree* left;
setTree* right;
```
这个类需要定义三个方法，除了之前我们已经学习实践过的setStatus和getStatus之外，需要一个remove.这个是用来保证线段树在空间上高效的重要操作。
```
1. void remove(setTree* & node)
2. bool setStatus(int a, int b, bool tracking)
3. bool getStatus(int a, int b)
```
首先我们特别关注一下remove。它是用来干什么的呢？我们设想，当我们在一个很大的范围内```[a,b)```做setStatus操作（比如设置为true)的时候，如果这个这个区间内已经有很多的子树（即说明其中有些区域是true，有些区域是false，这些子区间们可能犬牙交错），那么这些分支其实在这个操作之后都是完全可以“抹平”的。所以我们试图把这些子节点都删除，并把当前节点范围```[start,end)```内的status整体比标记为true。
```cpp
        void remove(SegTree* &node)
        {
            if (!node) return;
            remove(node->left);
            remove(node->right);
            delete node;
            node = NULL;
        }
```   
接下来再看setStatus。线段树模板写熟了之后，就能知道我们总是根据三种情况讨论：1.[a,b]与这个区间完全不相交（一般就是返回） 2.[a,b]包括了整个区间（一般就是整体赋值），3. [a,b]与该区间相交，这种情况下基本都是要再递归处理。

在这里，第二种情况下，我们需要添加一个remove操作，以保证线段树的空间高效。因为整体抹平的区间后，我们是不需要再有任何子区间的。另外，需要提醒的是，递归操作后，我们还需要及时更新当前区间的status。和之前的线段树的题目不同，我们这里，即使是非底层节点的status也是有意义的，true表示该区间都是tracked，反之就说明没有全部被tracked。这个对于getStatus函数是很有用的信息，这样我们就不用总是递归到最低层节点即可返回结果。
```cpp        
        void setStatus(int a, int b, int s)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回原先的状态
                return;                        
            if (a<=begin && end<=b)            // 2. [a,b]包括了整个区间，将该区间抹平
            {
                remove(left);
                remove(right);
                status = s;
                return;
            }         
                                                // 3. 其他情况，[a,b]与该区间相交，需考虑其子树。
            if (!left)                          // 没有子树？那就自己建立子树，子树的status从当前节点继承。
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(begin,mid,status);
                right = new SegTree(mid,end,status);
            }            
            leftStatus = left->setStatus(a,b,s);
            rightStatus = right->setStatus(a,b,s);
            status = left->status && right->status;     //记得更新当前节点的status
            return;
        }
```
第三个方法就是getStatus。依然是套路，分三类讨论：1.完全不相交（这里就返回一个无关紧要的true），2.完全包含（这里就返回该节点区间的status），3.部分相交，基本上需要用到递归。当然，这里有个额外的小trick，也就是，如果当前节点已经没有子树了，也可以直接返回它的status。
```cpp
        int getStatus(int a, int b)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回一个不影响结果的状态
                return true;            
            if (a<=begin && end<=b)            // 2. [a,b]包括了整个区间，返回该区间的状态
                return status;                        
            if (!left)                         // 3. [a,b]与该区间相交，但又没有子树，返回整个区间状态
                return status;
            int mid = (end-begin)/2+begin;      // 4. [a,b]与该区间相交，需要考虑其子树
            int leftStatus = left->getStatus(a,b);
            int rightStatus = right->getStatus(a,b);
            return leftStatus && rightStatus;            
        }
```        


[Leetcode Link](https://leetcode.com/problems/range-module)