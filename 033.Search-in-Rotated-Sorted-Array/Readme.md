### 33. Search-in-Rotated-Sorted-Array
此类型题目的突破口是利用nums[left]，通过比较nums[left]和nums[mid],nums[left]和target，来确定三者之间的位置关系。
```cpp
            if (nums[left]<nums[mid] && nums[left]<target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]>nums[mid] && nums[left]>target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<nums[mid] && nums[left]>target)
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<target)    
                right = mid;
```
还需要考虑一些边界情况：
1. 在每回确定 mid = left+(right-left)/2 的时候，就可以顺便查看 nums[mid]==target 提前判断。同理，也需要查看 nums[left]和nums[right]，因为在上个循环right=mid+1，不会被检验到。
2. nums[left]==nums[mid]怎么办？也就是left==mid怎么办。所以当left+1==right时可以提前处理。
