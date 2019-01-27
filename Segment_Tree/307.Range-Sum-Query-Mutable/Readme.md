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
除了Binary Indexed Tree，此题的另外一种解法是采用数据结构“线段树”。线段树的本质是一棵二叉树，每一个节点代表着一个区间。子节点区间都是父节点区间的二分子集。线段树适合的题型有非常鲜明的特点，即一个大区间的问题可以分解为若干小区间来求解并归并。比如一个大区间的sum，等于两个子区间sum的和；再比如，一个大区间的max，等于两个子区间max的最大值。构建线段树的时间复杂度、空间复杂度都是o(2n)，查询、更新（单个元素）是o(logn)，总和性能还不错。

线段树的模板比较长，常见的操作包括buildTree，modifyTree和queryTree。但思路非常清晰简洁，如果写熟练了，并不比TrieNode模板慢。需要注意的是，在本题里，最底层的子树一定会是```start==end```，这种结构比较特殊，反而降低了难度。更general的线段树会更难写一些。

首先，我们来设计线段树的结构。和二叉树类似有左子树和右子树（默认是NULL），但关于自身节点的属性有三个，其中```sum```表示了该线段的性质（在本题中表示这个区间内元素的和），有点像二叉树里的val；同时还有着两个```start,end```表示了该线段的起点和终点（在本题中就是数组的index区间），这对遍历整颗树非常关键。
```cpp
class SegmentTree
{
    SegmentTree* left;
    SegmentTree* right;
    int sum;
    int start,end;
    SegmentTree(int a, int b):start(a),end(b),left(NULL),right(NULL){}
};
```
接下来，我们怎么来构建整棵树？本题中我们已经有了所有的数据（完整的数组），想构建的是一棵近乎平衡的二叉树，用不断二分的思想不断向下递归即可。
```cpp
void buildTree(SegmentTree* node, int a, int b, vector<int>&nu)
```
