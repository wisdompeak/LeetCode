### 1300.Sum-of-Mutated-Array-Closest-to-Target

这是一道典型的二分搜值的问题。我们猜测某个value，查看数组之后的sum是否大于target。如果sum>=target，那么说明我们可以把value降一点（这样使得sum会变小）。反之，如果sum>=target，那么说明我们可以把value升一点（这样使得sum会变大）。这样直至我们找到恰好使得sum比target大的那个value。自然，value-1就是恰好使得sum比target小的那个value。对于最终的答案，我们需要在二者之间选择一个更接近target的sum。

但是本题有一个非常隐蔽的corner case。如果初始有的sum就已经小于target了，那么无论你如何操作都不能使得sum大于target。上述的二分法其实是失效的。对于这种情况，我们需要输出的答案是arr里面的最大值。
