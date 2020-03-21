### 668.Kth-Smallest-Number-in-Multiplication-Table

此题非常巧妙地用到了二分（值）查找的思想。

初始状态left=1,right=n\*m，每次确定mid之后，计算乘法表里小于等于mid的数目。这只要按照行i=1:m进行遍历就行，count+=min(mid/i,n)。(注意有一个上限n)

如果得到的count<k，那么显然这个mid太小，不满足条件，需要上调左边界，即left=mid+1；反之，count>=k的话，则说明这个mid可能太大但也可能正好就是答案（例如有很多重复的mid），无法确定，因此可以将其纳入右边界（闭区间），即right=mid，（因为答案不可能比mid更大了）。

这种二分逼近得到的结果 x 是什么呢？得到的是乘法表里小于等于x的元素个数不少于k的、且最小的那个数字。这其实就是待求的第k个元素。

但注意有一个问题需要考虑，最终左右指针相遇得到这个数x一定会是出现在乘法表里的吗？表面上看不出来，但答案是肯定的。这是因为满足“乘法表里小于等于x的元素个数不少于k的”，这样的x可能会有很多，但最小的那个一定是出现在乘法表里的。

PS: 本题本质上和 ```378. Kth Smallest Element in a Sorted Matrix```一模一样。


[Leetcode Link](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table)