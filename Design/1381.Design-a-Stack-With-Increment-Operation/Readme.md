### 1381.Design-a-Stack-With-Increment-Operation

本题虽然暴力解可以AC，但是有o(N)的优秀解法。用到的就是差分数组的原理。类似的题有```1109.Corporate Flight Bookings```

假设当我们遇到increment(k,val)操作时，我们设置offset[k]=value。这样当我们退栈的过程中遇到第k个元素的时候，就知道从此往下继续退栈的话，所有的元素都要加上一个diff = value。如果往下退栈的过程中再遇到另一个offset[k2] = value2，就知道从k2往下继续退栈出的元素都要加上一个diff = value+value2.

特别注意的是，当如果你需要入栈第k个元素的时候，你需要记录offset[k-1] = diff，同时将手头的diff清空。
