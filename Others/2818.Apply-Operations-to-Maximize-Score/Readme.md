### 2818.Apply-Operations-to-Maximize-Score

这道题是很多套路和知识点的大杂烩。

首先，根据题意，我们要在n^2个区间里挑选k个区间。这n^2个区间里，有的x可以很大，有的x会很小。我们不会去遍历所有这n^2个区间、再根据他们的x排序。相比之下，x的取值范围只有n种（即nums里的n个元素），通过遍历x来枚举区间的效率更高。

显然，我们必然会贪心地使用“x最大”的那些区间，我们将nums数组里最大元素记做nums[i]。那么有多少区间的`highest prime score`是nums[i]呢？假设每个元素的`prime score`我们都已经提前计算好了，记做scores[i]，那么我们寻找i左边第一个大于等于scores[i]的位置left，以及右边第一个大于scores[i]的位置right，那么符合条件的区间的左边界就可以在(left,i)之间任意选取，右边界就可以在(i,right)之间任意选取，任意配对之后总共的区间个数就是`(i-left)*(right-i)`. 也就是说，在最终选取的k个区间里，我们优先选取这`(i-left)*(right-i)`个区间，因为每次都可以让结果乘以nums[i]（全局最大的x）。

以此类推，我们再贪心地使用“x第二大”的那些区间，记做nums[j]。同理计算出有多少个区间满足scores[j]是最大元素。当k还没选够时，我们就会优先使用这些区间。

再找nums第三大元素、第四大元素... 直至把k个区间都用完。

以上就是本题的大致思路。其中还有不少小问题。比如

1. 怎么预处理得到scores数组？可以用埃氏筛的思路，在根据某个质因数向上筛除合数时，可以顺便给该合数增1，就可以记录下每个数的distinct质因数的个数了。
2. 如何求`previous larger or equal number`和`next larger number`，这是单调栈的经典应用了。
3. 假设某个数x对应的区间有P个，那么我们就要`ret *= x^P`，其中P可能很大，所以需要调用快速幂的libary。
