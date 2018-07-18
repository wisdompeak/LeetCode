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

此题适合标准的线段树模型和数据结构。

在segTree类中，需要有如下成员变量
```
int begin, end;
bool tracked;
segTree* left;
setTree* right;
```

需要定义三个方法：
```
1. void remove(setTree* & node)
2. bool setTracking(int a, int b, bool tracking)
3. bool setTracking(int a, int b)
```
```cpp
        void remove(SegTree* &node)
        {
            if (!node) return;
            remove(node->left);
            remove(node->right);
            delete node;
            node = NULL;
        }
        
                int setStatus(int a, int b, int s)
        {
            if (begin>=b || end<=a)            // 1. [a,b]与这个区间不相交，返回原先的状态
                return status;                        
            if (a<=begin && end<=b)            // 2. [a,b]包括了整个区间，将该区间抹平
            {
                remove(left);
                remove(right);
                return status = s;
            }         
            if (!left)                         // 3. [a,b]与该区间相交，需考虑其子树
            {
                int mid = (end-begin)/2+begin;
                left = new SegTree(begin,mid,status);
                right = new SegTree(mid,end,status);
            }            
            int leftStatus = left->setStatus(a,b,s);
            int rightStatus = right->setStatus(a,b,s);
            return status = leftStatus && rightStatus;
        }
                
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
