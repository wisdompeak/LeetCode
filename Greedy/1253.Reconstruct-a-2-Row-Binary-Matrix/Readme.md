### 1253.Reconstruct-a-2-Row-Binary-Matrix

容易知道，当colsum==0时，上下两行都要赋值0；当colsum==2时，上下两行都要赋值1.那么当colsum==1时，我们是否该任意给上一行或下一行赋值1呢？

这时有一个比较保守但有效的策略，那就是用upper和lower来统计上/下行分别还有多少个1还没有被使用。如果upper>lower，那么就优先给上一行赋值1，反之就优先给下一行赋值1.这样做是为了应对colsum==2的情况，保证上下行都尽量能存留有足够的1.举个例子，如果upper远多于lower，那么等lower降至0的时候，再碰到colsum==2的情况时就没有可行解了，之前全部的尝试都要作废。

如果采用了上述的保守的贪心策略，但最终还是遇到了colsum==2且lower为0的情况，那么说明了这个题就没有解，直接返回空就行了。

另外，本题有两个细节要注意。（1）当upper>=lower时，仍要检查upper是否大于0才可以给上一行赋值1. 反之同理。（2）当colsum全部走过一遍之后，仍需要保证此时upper==0 && lower==0 才能说明有解，也就是说初始状态下需要满足sum(colsum)==upper+lower。


[Leetcode Link](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix)