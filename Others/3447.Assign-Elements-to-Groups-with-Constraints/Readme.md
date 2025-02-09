### 3447.Assign-Elements-to-Groups-with-Constraints

突破点在于groups里的元素的数值不超过1e5.在这个范围是，如果枚举所有1的倍数，然后枚举所有2的倍数，然后枚举所有3的倍数，直至枚举n的倍数，那么总共的时间复杂度是`n+n/2+n/3+...n/n = n*(1+1/2+1/3+...1/n)`.这个级数虽然不收敛，但是它是趋近于nlog(n)的。所以本题可以用暴力枚举。

所以本题的算法很简单。我们开一个长度为1e5的数组assign，来记录每个自然数最早能被哪个element所assign。我们依次考察element里的每个元素，比如说elements[j]=x，然后枚举x的所有倍数（直至1e5），比如说kx，那样就有`assign[kx] = j`，当然根据题意，我们对于每个assign我们只更新一次。

最后根据groups的数值，从assgin里把答案拷贝过去即可。
