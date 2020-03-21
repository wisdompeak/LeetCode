### 255.Verify-Preorder-Sequence-in-Binary-Search-Tree

#### 解法1：常规的DFS

根据preorder的首元素（根节点）通过大小的比较，将后续元素分为属于其左子树和右子树的子区间，分别递归调用 
```cpp
bool DFS(vector<int>& preorder, int start, int end)。
```
边界条件：到end-start<=1时，就可以返回true

注意到，第一轮遍历判定左子树之后，还需要在第二轮对该左子树的左子树再做一回遍历比较，不断递归，有相当多的重复计算量。此题最坏情况下需要o(n^2)的时间复杂度，会非常慢。

#### 解法2：巧妙的o(n)解法

遍历这个序列，一旦出现先后的两个元素 a<b，说明a、b是同一个某左子树上的升序排列。之后出现的任何元素相对于a来说一定都是右子树元素，必定要比a大，任何c<a的情况都是不合法的。

于是本题转化为：如何在遍历preorder的过程中，不断更新a<b，使得a不断得以抬升（当前所有a<b的pair中最大的a），一旦出现后续的c<a即可宣告false

怎么维护一个最新（尽量大）的a<b呢？那就是用栈来维护一个递减的序列。一旦遍历的过程中出现了 preOrder[i]>Stack.top()，那就说明出现了递增序列，需要不断退栈直至保证栈本身仍然是递减的。在退栈的过程中，就不断遇到a<b的情况，借机可以抬高a。


[Leetcode Link](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree)