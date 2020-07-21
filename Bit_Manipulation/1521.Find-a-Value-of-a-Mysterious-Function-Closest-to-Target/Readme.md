### 1521.Find-a-Value-of-a-Mysterious-Function-Closest-to-Target

考虑s集合包含了所有以元素i结尾的subarray的bitwise AND的结果。那么这个集合有多大呢？其实并没有i个，而是最多只有32个。因为这些subarray的bitwise AND的本质，都是针对A[i]的某些bit进行从1到0的翻转。并且这些subarray bitwise AND从后往前来看都是不可逆的。具体地说，A[i], A[i]&A[i-1], A[i]&A[i-1]&A[i-2], ... 它们的bit 1的个数只会越来越少。因为A[i]最多只有32个1，所以所有这些subarray最多只会有32个不同的bitwise AND的结果。

既然s只有32个元素，那么只需要遍历一遍就可以找到最接近target的值。然后在考虑A[i+1]，并更新s集合：只需要将每个s的元素与A[i+1]进行AND，再添加A[i+1]即可。同理可知，此时的集合s依然最多只有32个元素。
