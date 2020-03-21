### 448.Find-All-Numbers-Disappeared-in-an-Array

对于这种数列[1,..,N]摆放在index为[1,..,N]的数组，有一种比较常见的巧妙解法，就是index sorting.

我们观察一个i位置上的数，如果nums[i]!=i的话，那么说明这个nums[i]本不应该在这个位置上，于是我们就把它送到它应该待的地方，也就是index为nums[i]的地方，直至这种交换无法继续为止。什么情况下无法继续呢？一种就是nums[i]==i，说明位置i已经放置了应该出现的数；另一种就是nums[nums[i]]==nums[i]，也就是打算安排nums[i]的位置已经有一个合适的数在那里了，我们也无法继续了，说明位置i上注定无法放置期望出现的数。

核心代码如下：
```cpp
        while (i<nums.size())
        {
            if (nums[i]==i || nums[nums[i]]==nums[i])             
                i++;            
            else            
                swap(nums[i],nums[nums[i]]);            
        }
```        
此题本质上和 442. Find All Duplicates in an Array 一模一样，只不过最终输出的内容是index而不是元素的值。


[Leetcode Link](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array)