### 307.Range-Sum-Query-Mutable

#### Binary Indexed Tree
此题用到了一种比较不常见的数据结构 Binary Indexed Tree. 参考(http://www.cnblogs.com/grandyang/p/4985506.html). 总的来说，这种数据结构累加一部分元素，又留着一部分元素，是一种兼顾“查找元素本身”和“查找元素和”的中庸方法。

这种数据结构的特征是：元素的标号（index）从1开始。第i个元素的变化，之后影响到的依次以此是 i+= (i&-i)。举个列子：     
第1个元素影响到：1,2,4,8,16，...      
第2个元素影响到：2,4,8,16，...   
第3个元素影响到：3,4,8,16，...   
第4个元素影响到：4,8,16，...   
总的来说，一个元素的变化，影响到整个Binary Indexed Tree的节点变化数目是 log(n)，比传统“累加和数组”牵一发动全身的数据结构而言，会优越很多。

总结一下这种数据结构的初始化方法。nums是原始的数据（数组），tree是Binary Indexed Tree，本质也是一个数组。注意，两者的元素标号都是从1开始，标号为0的元素没有意义。
```cpp
for (int i=1; i<nums.size(); i++)
{
    for (int j=i; j<nums.size(); j+=(j&-j))
      tree[i]+=nums[i];
}
```
相应地，如果想更新nums[i]，则对应的tree的变化
```cpp
  int update(i,new_val)
  {
    int diff = new_val - nums[i];
    for (int j=i; j<nums.size(); j+=(j&-j))
      tree[j]+=diff;  
    nums[i] = new_val;  
  }
```
对于nums前k个元素之和，需要在tree中累加的元素标号依次是 k-=(k&-k)，举个例子：    
nums的前8个元素之和，需要累加的的tree元素：8   
nums的前7个元素之和，需要累加的的tree元素：7,6,4   
nums的前6个元素之和，需要累加的的tree元素：6,4   
nums的前5个元素之和，需要累加的的tree元素：5,4   
由此看来，平均需要在tree里累加的元素和的数目也是log(n)，虽然比不上纯的累加数组，但也算很高效。
```cpp
    int getSum(int i)
    {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) 
        {
            res += tree[j];
        }
        return res;        
    }
```

#### Segment Tree
此题是应用线段树的典型例子。线段树的模板有很多种写法，这里来讲一下最基础的版本。

首先定义线段树节点
```cpp
    class SegTreeNode
    {
        public:
        SegTreeNode* left;
        SegTreeNode* right;
        int start, end;
        int info;        
        SegTreeNode(int a, int b):start(a),end(b),info(0),left(NULL),right(NULL){}
    };
```
其中的info是存储我们想在线段树加载的信息，在这里，存储的是下面所有叶子节点的数值的和。

第一个常用的API就是初始化：```void init(SegTreeNode* node, int a, int b)```，其意义是对以node为根节点的线段树进行节点的赋值，在其下面构造b-a+1个叶子节点，每个节点（id）对应的元素值从全局变量nums[id]里面读取和写入。显然，这种写法下，初始化只要一步：```init(root, 0, n-1)```.

第二个API就是单点修改：```void updateSingle(SegTreeNode* node, int id, int val)```，其意义是对以node为根节点的线段树时，修改nums[id]所对应的叶子节点的info为val。

第三个API就是区间查询：```int queryRange(SegTreeNode* node, int a, int b)```，其意义是对以node为根节点的线段树时，查询nums[a:b]区间所对应的所有叶子节点的info的和。

[Leetcode Link](https://leetcode.com/problems/range-sum-query-mutable)
