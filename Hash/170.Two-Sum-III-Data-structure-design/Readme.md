### 170.Two-Sum-III-Data-structure-design

不要试图构建一个存放所有两两之和的Set，那样会超时。

正确的思想应该是构建元素及其出现次数的映射 unordered_map<int,vector<int>>Map，因为这样的Map本身兼具Set的元素不相容的功能. 

当find(val)时，遍历所有Map里的元素x，查找val-x是否也在Map里。同时需要考虑x=val-x的情况。


[Leetcode Link](https://leetcode.com/problems/two-sum-iii-data-structure-design)