### 698.Partition-to-K-Equal-Sum-Subsets

#### 解法1：搜索
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

#### 解法2：状态压缩DP
此题有一种非常巧妙的状压DP的算法。因为本题中nums的个数最多只有16个，那么任意subset的总数不超过2^16=65536，可以用n位的二进制数来表示。另外我们令target=sum/k，表示期望每个subset的元素和。

本题里的dp[state]的定义比较有意思：以state所代表的subset，如果它可以分割成若干个“元素和是target的集合”，再加上若干个总和不超过target的元素零头，那么dp[state]就表示为subset的元素总和对于target的取余（也就是所说的零头）；否则dp[state]设为-1.

举个例子，如果state代表的是{1,2,3,4}，target是4，那么因为这个state可以分割成{4},{1+3},{2}，所以dp[state]=2. 为什么这么定义dp呢？这是因为，如果当前dp[state]的值不是-1，那么我们只需要关心的今后是否能有新的元素可以补足目前的零头凑成另一个target。以这个例子来说，如果再来一个新元素是1加入目前的subset，新元素1和旧元素2放入待定区，那么可以就得到dp[state2]=3；同理，如果再来一个新元素是2加入目前的subset，新元素2和旧元素2恰好凑成一组target的集合，于是dp[state2]=0；但是如果再来一个新元素是3，已有的零头2加上3就超过了target，说明新来的3无法与目前的零头凑成一组target的集合，所以我们就放弃dp[state2]的更新。

所以我们本题状态转移的思想是，根据当前的state，考察可以加入哪些新元素（比如说i）得到新的state2，使得```dp[state]+nums[i]<=target```。满足的话，那么就可以更新dp[state2]为该组合的元素之和对于target的取余（零头）。

最终的答案就是考察state=(1<<n)-1时的dp值是否不为-1. （其实，如果dp值不为-1的话，它一定是0，因为我们预判了所有元素之和必然要被target整除）

该解法的时间复杂度是```2^n*n```.

[Leetcode Link](https://leetcode.com/problems/partition-to-k-equal-sum-subsets)
