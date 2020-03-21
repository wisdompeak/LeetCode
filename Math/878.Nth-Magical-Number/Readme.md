### 878.Nth-Magical-Number

这道题和```1201. Ugly Number III```属于同一个类型，思想上还更简单。Binary Search可以是一个解法。但仍然有一个隐患，就是我们对于搜索的上限（区间的右端点）其实并没有一个合理的估计，可能需要设定为int64的最大值，甚至还可能更大。

在比赛中，我没有使用二分，而是用了周期性的特征。假设A，B的最小公倍数是LCM，那么以LCM为周期，其中出现的magic number的个数都是一样的，即```k = LCM/A+LCM/B-LCB/gcd(A,B)```.因此我们可以计算出第N个魔法数，其实是经过了p=N/k个整数周期，此外再加上```t=N-p*k```个零头。显然这个零头t肯定是小于k的，而且第t个魔法数也一定是在LCM的范围内的。

所以，本题转化为求[1,LCM)范围内的第t个魔法数r。而最终的答案就是 p*LCM+r.

怎么求[1,LCM)范围内的第t个魔法数r？简单的枚举就行了，依次检查A和B各自的倍数（即A*i和B*j），选取较小的那个就是next magic number。直至找到第t个为止。


[Leetcode Link](https://leetcode.com/problems/nth-magical-number)