### 15.3Sum
这是双指针算法的基本题，必须熟练掌握，快速准确地实现。

#### 需要注意的细节：
0. 一定要先排序。
1. 为了避免重复，仅在确认发现了一组解之后再移动left和right指针略过重复项。不要先略过重复项再判断是否解成立。
```cpp
  if (nums[left]+nums[right]==sum)
  {
     记录结果;
     left++;
     right--;
     while (left<right && nums[left]==nums[left-1]) left++;
     while (left<right && nums[right]==nums[right+1]) right--;
  }
```
2. 对于最外层的循环，也是确定一个，先展开内层循环，再略过最外层的重复项。
```cpp
 for (int a=0; a<nums.size(); a++)
 {
    inner loop;
    while (nums[a]==nums[a+1]) a++;
 }
```

[Leetcode Link](https://leetcode.com/problems/3sum)
