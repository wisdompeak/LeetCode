### 501.Find-Mode-in-Binary-Search-Tree

做中序遍历，这样保证遍历的元素都是递增的顺序。实时更新prev,currentFreq,maxFreq和results。注意maxFreq==0是做特殊处理。


[Leetcode Link](https://leetcode.com/problems/find-mode-in-binary-search-tree)