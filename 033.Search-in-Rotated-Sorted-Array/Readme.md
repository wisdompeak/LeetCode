### 33. Search-in-Rotated-Sorted-Array
#### 解法1
此类型题目的突破口是利用nums[left]，通过比较nums[left]和nums[mid],nums[left]和target，来确定三者之间的位置关系。
```cpp
        while (left<right)
        {
            mid = left+(right-left)/2;            
            if (nums[mid]==target) return mid;            
            if (nums[left]<=nums[mid] && nums[left]<=target || nums[left]>nums[mid] && nums[left]>target) //在同一个区段
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<=nums[mid] && nums[left]>target) //在不同区段
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<=target) //在不同区段   
                right = mid;                
        }
```
在每回确定 mid = left+(right-left)/2 的时候，就可以顺便查看 nums[mid]==target 提前判断。

#### 解法2
其实也可以将nums[mid]、target分别与nums[0]进行比较，来判断mid和target是否处在同一个区间。
```cpp
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[mid]==target) return mid;            
            if (target>=nums[0] && nums[mid]>=nums[0] || target<nums[0] && nums[mid]<nums[0])
            {
                if (nums[mid]>target)
                    right=mid;
                else
                    left=mid+1;
            }
            else if (target>=nums[0] && nums[mid]<nums[0])
                right=mid;
            else if (target<nums[0] && nums[mid]>=nums[0])
                left=mid+1;
        }
```        
