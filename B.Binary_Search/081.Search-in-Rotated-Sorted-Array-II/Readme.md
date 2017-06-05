### 81.Search-in-Rotated-Sorted-Array-II

此题是154和81的结合体。

解题思路大致是：   
1. 比较nums[left]和nums[mid]、target的大小，确定三者所处的区间关系。
2. 因为允许重复元素的存在，当x==nums[left]时是无法确定x所处的区间。提前如下处理，这样x<=nums[left]可以归并一类，定位在右区间。    
```cpp
  while (left+1<right && nums[left]==nums[left+1]) left++;
```
3. 每个循环都提前处理 nums[left],nums[mid],nums[right]等于target的情况。   
