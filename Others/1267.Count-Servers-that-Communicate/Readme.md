### 1267.Count-Servers-that-Communicate

此题乍看之下和```947. Most Stones Removed with Same Row or Column```非常相似。可以通过同行（同类）的元素归并为一类的Union Find算法，计算得到所有servers可以归类哪几个group，然后统计那些所含元素不为1的group。

但是本题其实有更简单的算法。我们只要在预处理中统计每行每列的元素各有多少个。对于那些同行/同列里都只有一个元素的server，就肯定不会与其他元素connected；反之就是会与其他元素connected。


[Leetcode Link](https://leetcode.com/problems/count-servers-that-communicate)