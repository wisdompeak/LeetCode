### 283.Move-Zeroes

思考如何用in-place实现。  
基本思想是用双指针。方案1：让右指针遇到非零的数就扔到左边；方案2：让右指针遇到0就扔到右边。

#### 方案1：
```cpp
int left=0;
int right=0;
```
a 当遇到 nums[right]==0时应该如何操作呢? 既然非0的都已经扔到了左边，那么右指针遇到0就继续前进。

b 当遇到 nums[right]!=0时应该如何操作呢?     
首先，把这个数扔到左边去:
```cpp
swap(nums[left],nums[right])
```
然后，nums[left]已经是非0数，故可以放心 left++.    
那么右指针呢？关键点来了，如果left!=right的话，左指针一定指向的是0，因为左右指针之间拉开的差距的原因，就是因为有0的存在。右指针是踏着0才能前进的，所以左指针原先指向的必定是0，交换之后右指针也是0，故可以继续right++

综上：
```cpp
        while (right<nums.size())
        {
            if (nums[right]==0)
            {
                right++;
            }
            else
            {
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
                
        }
```

类似的题目：
 75.Sort-Colors


[Leetcode Link](https://leetcode.com/problems/move-zeroes)