### 81.Search-in-Rotated-Sorted-Array-II

此题是154和81的结合体。

需要注意的地方有：   
1.考察nums[left],nums[mid],target的区间关系。方法是先比较nums[left]和nums[mid]、nums[left]和target，得到nums[mid]和target所在的区间，然后再是传统的二分思路，比较nums[mid]和target。   
2.每个循环都提前处理 nums[left],nums[mid],nums[right]等于target的情况。循环体中就不会出现nums[left]==target的情况。   
3.遇到nums[left]==nums[mid]时，left++，这样永远都不会有nums[left]==nums[mid]的情况。   
