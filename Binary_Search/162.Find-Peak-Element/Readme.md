### 162.Find-Peak-Element

解题思路：注意题目条件，1：相邻的元素不会相等。2： 首尾的斜率。

我们可以根据mid本地的斜率来判断指针移动的方向，搜索方向朝向元素增大的一侧。

因为 mid = left+(right-left)/2，所以在 while (left<right) 成立的情况下，mid永远都不会与right重合，因此 nums[mid+1]永远是合法的。
所以我们考察 nums[mid]和nums[mid+1]
``` cpp
            if (nums[mid]>nums[mid+1])
                right = mid;
            else  // 要么右侧方向增大，要么mid本身就是极大点
                left = mid+1;
```


[Leetcode Link](https://leetcode.com/problems/find-peak-element)