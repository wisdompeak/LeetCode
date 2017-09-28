### 128.Longest-Consecutive-Sequence

遍历nums，每读入一个数a，分别查看a+1和a-1是否已经收录。是的话就对这两个数尝试进行Union。

最后用一个哈希表unordered_map<int,unordered_set<int>>Map，把所有具有相同Father的数都收集在一个集合里。查看每个集合，找出元素最多的那个。
