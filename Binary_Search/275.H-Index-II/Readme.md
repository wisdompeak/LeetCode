### 275.H-Index-II

此题有很多做法，参见 274 H-Index. 但用时最快的应该是二分搜索的方法。

将citations数组排序后，按位置进行常规的二分搜索。如果发现 citations[mid]==N-mid(从右往左累加的文章总数)，则可以证明 H-index 就是 citations[mid]，因为继续左移的话citation必定会减少，右移的话则文章总数（从右往左计算引用数大于citations[mid]的）会减少，故不可能有其他的解。  

如果最后收敛到left==right仍没有退出，请仔细考虑会是什么情况. 此时查看citations[left]（引用数） 和 Citations.size()-left（文章数）哪个更小，即为H-index.
