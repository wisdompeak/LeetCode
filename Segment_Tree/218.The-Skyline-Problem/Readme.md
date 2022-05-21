### 218.The-Skyline-Problem

#### 解法1:扫描线

我们维护一个multiset，按照横轴的位置顺次考虑各个楼的上升沿和下降沿。遇到上升沿就往集合里加入一个H，遇到下降沿就在集合里删除一个H。这样每个时刻，集合里面的最大值，就代表了该位置（及其右边区间）的天际线高度。我们将这些```{位置，高度}```记录下来，就代表了天际线的轮廓。

注意，如果相邻两个位置的高度一样，那么我们可以只保留第一个。

类似的题目有```2158.Amount-of-New-Area-Painted-Each-Day```.

#### 解法2:线段树

此题的线段树解法，是以```370.Range-Addition```的懒标记版本为基础，稍加改动。

首先，不同于307或者370中已经给出了nums数组。此题中给出的是建筑物高度拐点的pos。这些pos的绝对值对我们而言其实是没有意义的，我们只关心这些pos的相对顺序，也就是idx。所以我们其实需要构造两个映射，pos2idx和idx2pos，方便我们做转换。转换之后，每个builiding相当于一个区间更新。特别注意，如果一个building对应的索引区间是```[i:j]```，那么我们只更新区间```[i:j-1]```。也就是说，线段树中的每个叶子节点的单点info，代表的其实是```[i:i+1)```这段左闭右开的小区间。

然后我们设计一下SegTreeNode的数据结构。除了常规的left,right,start,end之外，此时节点的info表示的是该区间内出现的高度最大值。注意，不一定整个区间都是该恒定的高度。此外，该节点的tag是一个bool量，表示该区间的高度是否都是相同的（也就是等于info）。tag为true时说明我们能断言整个区间的信息是一致的，我们不需要下沉去更新每一块更细的区间。下文会详细说明。

初始化函数```init(root, 0, n-1)```不需要特别的改动。其中n就是离散化之后有多少个数据点。初始化时，每个节点的info设置为0，tag设置为false。

区间更新函数```updateRange(node, a, b, val)```是本题的重点，意思是将区间[a,b]里的所有数据点的最大值更新为val（如果原最大值小于val的话）。我们分几种情况讨论：
1. 边界条件：[a,b]与该节点区间互斥，直接return。
2. 边界条件：该节点的区间是单点，那么```node->info = max(node->info, val)```然后return
3. 边界条件：如果该节点的区间包含在[a,b]内，并且```node->info <= val```，说明该节点区间的数据点可以统一更新为val。并且我们就设置tag标记true，根据之前的分析，我们可以直接返回而不用下沉去更新更细节的区间。
4. 其他情况下，我们就递归处理```updateRange(node->left, a, b, val) && updateRange(node->right, a, b, val)```。但是递归之前，我们别忘了查看当前的tag是否为true。如果是的话，说明当前节点的区间不再有统一的高度，我们需要去掉tag的标记，并且将其影响传递给两个子区间，即
```cpp
        if (node->tag == 1) // if current node tagged lazy, push information down
        {
            node->tag = 0;            
            node->left->info = node->info;
            node->right->info = node->info;
            node->left->tag = 1;
            node->right->tag = 1;            
        }   
```
对于此题，我们其实不需要写区间查询的函数。因为我们最终输出的结果，会要求遍历线段树的每一个节点，写个DFS即可。当然，如果遍历到某个区间的tag依然为true时，其实可以不用继续深入下去，直接输出该区间的信息。最终输出的结果需要整理一下，如果相邻的叶子节点的高度相同，我们再做一下归并。

另外补充一点，我们将所有的building按照高度从小到大排序一遍，会使带有懒标签的线段树代码跑得更快。这是因为在updateRange时有更大的概率触发下面这个条件，使得我们只需要标记lazy tag并立即返回：
```cpp
if (a <= node->start && node->end <=b && val >= node->info) 
{... return; }
```

[Leetcode Link](https://leetcode.com/problems/the-skyline-problem)
