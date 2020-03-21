### 713.Subarray-Product-Less-Than-K

本题有很明显的滑窗的特征，所以基本思路是用双指针。保证一个乘积小于k的最大窗口，这个窗口内可以构成subarray的数目就是j-i+1;

本题需要注意的一点是，当nums[i]>k时，右指针动不了，而左指针依然会顺移，所以可能会出现j<i的情况，此时只需要重置这两个指针即可：
```cpp
if (j<i)
{
    j = i;
    product = 1;
}
```


[Leetcode Link](https://leetcode.com/problems/subarray-product-less-than-k)