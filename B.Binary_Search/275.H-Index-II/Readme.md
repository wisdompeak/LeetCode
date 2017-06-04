### 275.H-Index-II

将citations数组排序后，按位置进行常规的二分搜索。如果发现 citations[mid]==N-mid+1，则可以退出反而H-index = citations[mid]，因为继续左移的话citation必定会减少，右移的话则文章总数（从右往左计算引用数大于citations[mid]的）会减少，故不可能有其他的解。  

如果搜索过程中没有退出，最后收敛到left==right，则查看citations[left]（文章数） 和 Citations.size()-left（引用数）哪个更小，即为H-index.
