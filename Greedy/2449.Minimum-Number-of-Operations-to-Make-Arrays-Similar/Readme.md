### 2449.Minimum-Number-of-Operations-to-Make-Arrays-Similar

很显然题目的意思是，nums经过一系列操作之后，需要变成targets。于是nums和targets的数组元素之和必然相等，否则无法实现+2/-2的守恒。

另外，我们发现，偶数无论如何也无法操作成奇数，反之亦然。所以知道，需要将奇数偶数分开处理，即nums里的奇数需要多少操作转化为targets里的奇数，同理nums里的偶数需要多少操作否转化为targets里的偶数。

接下来，我们考虑只含有奇数的nums数组和只含有奇数的targets数组。很明显，我们必然会把nums[0]转化为targets[0]，将nums[1]转化为targets[1]，依次类推。这样能使得每对元素差的绝对值之和最小。简单的证明可以从两对开始研究。假设有`nums[i]<nums[j]`和`targets[x]<targets[y]`，那么无非三种情况
1. nums[i]<nums[j]<targets[x]<targets[y]
2. nums[i]<targets[x]<nums[j]<targets[y]
3. nums[i]<targets[x]<targets[y]<nums[j]
画个线段图就发现，无论哪一种，都有`abs(nums[i]-targets[x])+ abs(nums[j]-targets[y]) <= abs(nums[i]-targets[y])+ abs(nums[j]-targets[x])`。将这个结论推广至任意两对元素之间的判断，就可以得出前面的结论。

有了这个策略之后，我们就可以计算出每对元素之间，需要多少次+的操作，或者多少次-的操作。但实际上我们只需要记录+的操作即可，因为题目保证最终全局（即包括了奇数数组和偶数数组）而言+和-的操作一定守恒。
