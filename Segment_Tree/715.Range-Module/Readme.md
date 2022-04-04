### 715.Range-Module

#### 解法1：使用有序map

我们需要在数轴上维护一个“干净的”区间序列，即每个区间从小到大排列，但彼此互不重合。每次addRange或removeRange时，都要依然维护区间的“干净”，这样queryRange时就方便很多。

类似2213，我们会选择C++的有序map，将左边界作为key，右边界作为val，则所有的区间都按key（即左边界）从小到大排序。

##### AddRange
加入一个新区间[left,right]时，我们考虑它与数轴上已有区间的关系。
```
      A            B         C         D
L____________   ______  __________R  _____
   left_____________________right
```
如上图所示，我们的目标是：删除已有的区间A、B、C，同时加入一个新的区间[L,R].

如何定位区间A？A是左边界最后一个小于left的区间。所以我们用```iter1=prev(Map.lower_bound(left))```来定位这个区间，同时它可以拓展左边界，即```L = iter1->first```. 注意如果prev操作会越界的话，那么iter1就定位在Map.lower_bound(left)，这是我们想要删除的最左边的区间。

如果定位区间C？其实更容易定位的是区间D，那么就是第一个左边界大于right的区间。所以我们用```iter2=Map.upper_bound(right)```来定位这个区间。于是从iter1到iter2（不包括iter2本身）这些区间都可以删除，于是直接用```Map.erase(iter1, iter2)```. 注意到prev(iter2)就是区间C，区间C的右边界可能帮助我们拓展右边界，即```R = max(right, prev(iter2)->second)```.

最终我们添加新的区间[L,R].

##### RemoveRange
删除一个新区间[left,right]时，我们类似地考虑它与数轴上已有区间的关系。
```
      A            B         C         D
L____________   ______  __________R  _____
   left_____________________right
```
如上图所示，我们的目标是：删除已有的区间A、B、C，同时加入两个新区间[L,left], [right,R].

如何定位区间A？同上，A是左边界最后一个小于left的区间。所以我们用```iter1=prev(Map.lower_bound(left))```来定位这个区间。如果这个区间存在并且左边界比left更早，那么我们就要添加[L,left].

如何定位C？同理，先定位区间D，即```iter2=Map.upper_bound(right)```，然后我们考察D的前一个区间C的右边界是否比right更晚，那么我们就要添加[right,R].

注意，我们必须显操作```Map.erase(iter1, iter2)```，再添加这两个新区间。

##### QueryRange

只要用prev(Map.upper_bound(left))定位到左边界小于等于left的区间，再看区间右边界是否大于等于right即可。

#### 解法2：使用线段树 （不推荐）

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
