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
        
        bool setTracking(int a, int b, bool tracking)
        {
            if (a<=begin && end<=b)     //如果该区间被包括在了[a,b]内,则整体标记
            {
                remove(left);
                remove(right);
                return tracked = tracking;
            }
            int mid = (end-begin)/2+begin;  //如果该区间和[a,b]只是部分相交,则需要往下搜索
            if (!left)      //如果没有子区间,则需要立即创建.注意子区间的tracked可以完全继承自该区间的tracked
            {
                left = new SegTree(begin,mid,tracked);
                right = new SegTree(mid,end,tracked);
            }
            bool leftTracked, rightTracked;
            if (a<mid)            
                leftTracked = left->setTracking(a,b,tracking);
            else
                leftTracked = left->tracked;
            if (b>mid)
                rightTracked = right->setTracking(a,b,tracking);
            else
                rightTracked = right->tracked;
            return tracked = leftTracked && rightTracked; // 父区间的tracked,永远来自两个子区间tracked的"与"
        }
        
        bool getTracking(int a, int b)
        {            
            if (!left && !right) return tracked;
            if (a<=begin && end<=b) return tracked;            
            int mid = (end-begin)/2+begin;
            bool leftTracked, rightTracked;
            if (a<mid)
                leftTracked = left->getTracking(a,b);
            else
                leftTracked = true;
            if (b>mid)
                rightTracked = right->getTracking(a,b);
            else
                rightTracked = true;
            return leftTracked && rightTracked;                
        }
```        
