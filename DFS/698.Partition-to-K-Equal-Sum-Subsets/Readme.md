### 698.Partition-to-K-Equal-Sum-Subsets

此题据说是NP-hard，没有什么特别高明的算法，就是老老实实地DFS，尝试将所有元素挨个尝试放入k个分类里，直至找到满足条件的分类。

设计如下的递归函数：```DFS(nums, curPos, curGroup, curSum)```.
注意边界条件的转换：
```cpp        
        if (curGroup==k) return true;
        if (curSum>SUM) return false;        
        if (curSum==SUM) return DFS(nums,0,curGroup+1,0);        
```        

另外，如果提前将所有元素从大到小排序，则有额外的优化效果：从大元素开始尝试的话，则可以迅速排除一些因为元素过大造成的negative测例。

此外，在for循环里遍历下一个候选元素时，有一个重要的剪枝手段：
```cpp
last = -1;
for (int i=curPos; i<n; i++)
{
    //...
    if (nums[i]==last)
        continue;
    last = nums[i];
    //...
```
这是因为若nums[i]=a已经被搜索过并且失败后回溯的话，有着相同数值a的其他nums元素就不需要再次被搜索了，注定是失败的。因为我们已经提前把nums排个序，保证了所有相同数值的元素都是相邻的，故很容易skip掉相同的候选元素。

与本题非常相似的题目有： 473. Matchsticks to Square, 416. Partition Equal Subset Sum, 996. Number of Squareful Arrays    


[Leetcode Link](https://leetcode.com/problems/partition-to-k-equal-sum-subsets)
