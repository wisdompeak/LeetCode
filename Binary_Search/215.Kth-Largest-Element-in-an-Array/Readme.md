### 215.Kth-Largest-Element-in-an-Array

此题比较简单的方法就是用priority_queue,遍历整个数组,每次只保留最大的K个值.

另外还有一个理论上o(N)的算法，就是二分搜值，猜测这个数是t。如果发现nums里大于等于t的个数大于等于k，那么我们可以猜测更大的t（注意t可能是答案），将下界上调为t；反之我们可以猜测更小的t（注意t不可能是答案），将上界下调至t-1。

最后上下界收敛的结果一定就是答案。



[Leetcode Link](https://leetcode.com/problems/kth-largest-element-in-an-array)
