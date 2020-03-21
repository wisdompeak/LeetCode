### 721.Accounts-Merge

此题是accounts的聚类，本质就是Union Find，不要被owner的名字所干扰。

初始化时，每个account的Father都是本身。对于一组account里的所有邮箱怎么做归并：完全等价于线性地处理每两个相邻邮箱的归并。每个group的Father可以定义为字典序最小的那个。

归并完之后，再遍历一次所有的邮箱，按照其Father分类就是答案所要求的分类。每个分类对应的人名，就是Father account对应的人名。


[Leetcode Link](https://leetcode.com/problems/accounts-merge)