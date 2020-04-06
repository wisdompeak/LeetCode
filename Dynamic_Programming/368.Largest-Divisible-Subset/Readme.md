### 368.Largest-Divisible-Subset

本题最直接的想法就是将nums排序之后用DFS搜索。但是DFS会超时。很显然其中有非常多的重复路径。

那是否可以通过一个visited的数组来标记已经访问过的元素来避免重复搜索呢？这样是不行的，因为按照从小到大的次序优先搜索到的并不是最优的解。例如 1,3,5,10,30,60 这个例子，会首先搜索到 1-3-30-60，但是它不及 1-5-10-30-60. 如果30和60在第一次搜索中已经标记为visited的的话，那么就会错过第二次搜索的最优解。

于是只有考虑o(n^2)的DP算法，思路和动态转移方程也是非常明确的。只不过本题不仅求最长解的长度，而且要把这个最长解打印出来。这样的DP问题虽不常见，但也是很容易解决的。除了用一个DP数组记录“状态”外；再用一个prev数组记录当前i元素在Largest-Divisible-Subset里之前的那个元素的位置。回溯的大致代码是：
```cpp
    while (prev[k]!=k)
    {
      result.push_back(nums[k]);
      k = prev[k];
    }
```


[Leetcode Link](https://leetcode.com/problems/largest-divisible-subset)
