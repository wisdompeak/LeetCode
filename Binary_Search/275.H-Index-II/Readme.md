### 275.H-Index-II

#### 解法1：

此题有很多做法，参见 274 H-Index. 但用时最快的应该是二分搜索的方法。

设文章总数N=citations.size()

将citations数组排序后，按位置进行常规的二分搜索。如果发现 citations[mid]==N-mid(从右往左累加的文章总数)，则可以证明 H-index 就是 citations[mid]，因为继续左移的话citation必定会减少，右移的话则文章总数（从右往左计算引用数大于citations[mid]的）会减少，故不可能有其他的解。  

如果最后收敛到left==right都没有退出，请仔细考虑会是什么情况？结合二分的判断条件，答案是：此时的元素i是使得(N-i)与citations[i]最接近的。故此时查看citations[i]（引用数） 和 Citations.size()-i（文章数）哪个更小，即为H-index.

#### 解法2：

最简洁的方法是：

从后面往前找，每找到一篇，说明有N-i篇论文，其最小的引用数是citations[i]。如果N-i<=citations[i]，说明我们仍然可以有机会增多文章数目（代表了H index），代价是再往前走减小文章引用数。找到满足条件的最小的i，得到最大的N-i，这样答案就是 H = N-i;


[Leetcode Link](https://leetcode.com/problems/h-index-ii)