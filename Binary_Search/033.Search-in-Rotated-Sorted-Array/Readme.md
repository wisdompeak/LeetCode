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

#### 解法3
有一个更巧妙的解法。普通的二分搜索，需要比较nums[mid]和target的值。本题中，因为nums[mid]和target可能不会再同一个单调区间，所以他们的比较对于指导[left,right]的update没有帮助。那么如果遇到这种情况，该怎么办呢？

我们发现，如果我们能判断出target在左边的单调区间，而nums[mid]在右边的单调区间，那么我们就直接将搜索范围移向左区间就行，方法就是```right=mid-1```。如果我们能判断出target在右边的单调区间，而nums[mid]在左边的单调区间，那么我们就直接将搜索范围移向右区间就行，方法就是```left=mid+1```。这样，常规的二分搜索就能迅速定位target了。

于是本题的关键就是判断nums[mid]和target它们各自在哪个区间？方法非常amazing，就是将它们各自与nums[0]比较大小的结果就行了！


[Leetcode Link](https://leetcode.com/problems/search-in-rotated-sorted-array)