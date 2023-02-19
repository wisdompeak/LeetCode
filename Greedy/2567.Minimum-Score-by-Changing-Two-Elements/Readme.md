### 2567.Minimum-Score-by-Changing-Two-Elements

设想，如果贪心地将两个修改的名额都用来降低 high score，我们可以有三种方法：(1) 将最大值改为次大值，最小值改为次小值，这样high score就是`nums[n-2]-nums[1]`. (2) 将最小的两个值都改为第三小的值，这样high score就是`nums[n-1]-nums[2]`. (2) 将最大的两个值都改为第三大的值，这样high score就是`nums[n-3]-nums[0]`.

此时我们发现，我们选取上述的哪个方案，因为出现了重复元素，所以low score都是零。

所以答案就是在三个high score里面挑最小值即可。
