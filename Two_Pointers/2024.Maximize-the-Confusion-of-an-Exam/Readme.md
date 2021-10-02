### 2024.Maximize-the-Confusion-of-an-Exam

本题和```LC 1004. Max Consecutive Ones III```非常相似。本质就是找一段最长的subarray，使得滑窗满足：除了0之外只有最多k个1，或者除了1之外只有最多k个0. 

比较简单的写法就是将上面两种情况分为两次pass来做。比如考虑“若干个0 + k个1”的情况。固定左边界i，探索右边界j的最远位置，一路统计需要flip的次数（即1的个数）直至flip达到上限k。此时```j-i+1```就是一个合法的解区间。然后移动左边界```i+=1```，再次调整右边界j。同理，对于“若干个1 + k个0”的情况，类似的代码。

本题其实还有参考```LC 424. Longest Repeating Character Replacement```，有one pass的实现方法。
