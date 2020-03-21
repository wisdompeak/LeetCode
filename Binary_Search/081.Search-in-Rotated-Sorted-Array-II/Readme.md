### 81.Search-in-Rotated-Sorted-Array-II

#### 解法1:

此题是154和33的结合体。

解题思路大致是：   
1. 比较nums[left]和nums[mid]、target的大小，确定三者所处的区间关系。
2. 因为允许重复元素的存在，当x==nums[left]时是无法确定x所处的区间。提前如下处理，这样x<=nums[left]可以归并一类，定位在右区间。    
```cpp
  while (left+1<right && nums[left]==nums[left+1]) left++;
```
3. 每个循环都提前处理 nums[left],nums[mid],nums[right]等于target的情况。   

#### 解法2:
和33题的解法2一样。总体思想就是查看nums[mid]和target是否在同一个单调区间。如果是的话，就套用传统的二分搜索，这个对于非严格递增的递增序列也是适用的。如果不是的话，则直接将搜索范围移向target所在单调区间。

和33题唯一的区别就是，当出现类似于```1 1 1 2 3 4 0 1 1```这种情况时，```if (nums[mid]>=nums[0] == target>=nums[0])```这个语句会失效，无法正确判断nums[mid]和target是否在同一个区间里。解决方法非常简单，就是将数组末尾的这些与nums[0]相同的数都去掉就行了。


[Leetcode Link](https://leetcode.com/problems/search-in-rotated-sorted-array-ii)