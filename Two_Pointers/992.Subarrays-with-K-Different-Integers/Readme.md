### 992.Subarrays-with-K-Different-Integers

此题的解法非常巧妙.它代表了一类思想:求关于K的解,是否可以化成求at most K的解减去求at most K-1的解.本题恰好就是用到这个方法.我们需要写一个helper函数,计算数组A里面最多含有K个不同数字的subarray的个数.于是最终答案就是```helper(K)-helper(K-1)```.

对于这个helper函数,标准答案很显然就是用双指针和滑动窗口的方法.遍历右指针,考察对应的最大的滑窗是多少.于是在该右边界固定的条件下,满足题意的subarray的个数就是```count+=右指针-左指针+1```


[Leetcode Link](https://leetcode.com/problems/subarrays-with-k-different-integers)