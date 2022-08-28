### 484.Find-Permutation

本题本质和`2375.Construct-Smallest-Number-From-DI-String`一模一样。

基本思想是将s的开头加上一个“I”，将s切分为若干"IDD..D"的pattern，每个pattern对应的是一段单调递减的序列。保证序列与序列之间不重合即可。

[Leetcode Link](https://leetcode.com/problems/find-permutation)
