### 154.Find-Minimum-in-Rotated-Sorted-Array-II

解题思路：和153. Find Minimum in Rotated Sorted Array 一样，需要以nums[left]为基准， 分别比较nums[mid]和nums[right]，以判断三者所在的区间（左区间还是有区间）。

此题的特别之处是，当出现x==nums[left]时，无法定位x所在的区间是左还是右。解决技巧是：
```cpp
while (left+1<right && nums[left]==nums[left+1]) left++;
```
这样，当出现x==nums[left]时,x必定是在右区间，可以和x<nums[left]归并；x>nums[left]则说明x在左区间。

所以分段讨论的方法如下：
```cpp
            if (nums[left]<nums[mid] && nums[left]<nums[right])  // left,mid,right同在一个区间
                right=mid;  // 可以直接 return nums[left]
            else if (nums[left]<nums[mid] && nums[left]>=nums[right]) // left,mid在左区间，right在右区间
                left=mid+1;
            else if (nums[left]>=nums[mid] && nums[left]<nums[right]) // mid在右区间,right在左区间，不可能
                continue;
            else if (nums[left]>=nums[mid] && nums[left]>=nums[right]) // left在左区间，mid,right在右区间
                right=mid;   
```
