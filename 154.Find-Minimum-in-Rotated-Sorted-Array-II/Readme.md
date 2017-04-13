### 154.Find-Minimum-in-Rotated-Sorted-Array-II

常规思路：根据 nums[mid], nums[left], nums[right] 的大小判断三者的区间关系。

当出现nums[left]==nums[mid]时，是无法定位mid所在的区间，技巧是：
```cpp
if (nums[mid]==nums[left]) left++;
```
当出现nums[left]==nums[right]时，如何定位right所在的区间? 注意到先前已经处理了mid，故此刻nums[mid]!=nums[left]，所以right一定是在rotate之后的区间（否则此时left到right必然都相等），可以归并至nums[left]>=nums[right]一同解决。
```cpp
            if (nums[left]==nums[mid])
                left++;
            else if (nums[left]<nums[mid] && nums[left]<nums[right])
                right = mid;
            else if (nums[left]<nums[mid] && nums[left]>=nums[right])                
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<nums[right])
                continue;  // impossible
            else if (nums[left]>nums[mid] && nums[left]>=nums[right])    
                right = mid;
```
