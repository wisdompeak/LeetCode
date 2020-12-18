### 645.Set-Mismatch

此题的难点在于如何设计不需要额外空间的方法。对于将数字1\~n存放在一个大小为n的数组，这个场景提示了一个很常用的经典的算法：array indexing，用于试图将乱序的1\~n顺序地重新放入这个数组。算法核心如下：
```cpp
for (int i=0; i<nums.size(); i++)
{
    while (nums[i]-1!=i)
        swap(nums[i],nums[nums[i]-1]);
}
```
解释：对于处于位置i上的数字nums[i]，如果nums[i]!=i+1，说明它没有放在正确的位置上。于是我们交换 nums[i]和nums[nums[i]-1]，那么原先的nums[i]就被放在了正确的位置上，而位置i上又有了一个新的数。while循环重复以上操作，直至位置i上有正确的数。外层的for循环将保证所有位置都存放对应的正确的数。时间复杂度是o(n)。

而此题有所不同，因为nums存放的并不是1\~n，上述算法中的while循环条件 nums[i]!=i+1 可能无法满足而死循环。改动的方法是在外面套一层nums：
```cpp
for (int i=0; i<nums.size(); i++)
{
    while (nums[i]!=nums[nums[i]-1])
        swap(nums[i],nums[nums[i]-1]);
}
```
这样的话，重复的两个数字最后会放在：一个在其应该的位置，一个在missing number的位置。

最后遍历一遍nums，找到 nums[i]-1!=i 的那个位置，这就提供了答案所需要的两个信息： 实际位于i位置上的那个元素就是重复的数字，本应位于i位置上的那个元素就是missing number。
```cpp
result = {nums[i],i+1};
```


[Leetcode Link](https://leetcode.com/problems/set-mismatch)
