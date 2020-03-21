### 128.Longest-Consecutive-Sequence

#### 解法１：　Union Find
遍历nums，每读入一个数a，分别查看a+1和a-1是否已经收录。是的话就对这两个数尝试进行Union。

最后用一个哈希表unordered_map<int,unordered_set<int>>Map，把所有具有相同Father的数都收集在一个集合里。查看每个集合，找出元素最多的那个。
  
#### 解法2：　Set
此题更加简洁，巧妙和高效的算法是如下．

将所有的元素放入一个集合中．然后我们再遍历一下这个数组nums[i]，如果nums[i]-1不在这个集合中，说明nums[i]可能是一个连续序列的下限，那么我们就从这个下限顺着递增去查验，找到一个完整的递增序列．如果nums[i]-1在这个集合中，说明它有更小的下限，那么我们就不去查验这个递增序列，因为我们规定，只有遇到了下限才会去查验整个序列．于是遍历完整个数组后，对于集合的查验也就仅仅是o(n)次．


[Leetcode Link](https://leetcode.com/problems/longest-consecutive-sequence)