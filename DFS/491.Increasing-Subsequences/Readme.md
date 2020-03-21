### 491.Increasing-Subsequences

典型的DFS的应用。在nums数组中遍历递增序列的第一项的可能值，确定了这个位置start之后，把锅甩给DFS让它从start+1开始找接下来的递增序列。

构造DFS函数：nums是题目给的数组，start表示需要开始探索的位置，curRes存放的是之前已经找到的递增序列。
```cpp
void DFS(vector<int>& nums, int start, vector<int>curRes)
```
用循环 for (int i=start; i<nums.size; i++) 遍历第一项的可能性。要排除几种情况：
1. DFS的终止条件：start已经超过了nums.size()，没有元素可以加入队列，就地返回。
2. 新元素无法接上之前的序列构成新的递增序列，即 nums[i]<curRes.back()
3. 重复。究竟什么情况会造成重复呢？假设i在遍历过程中先选择了a，加入了队列并以此进行深度搜索，穷尽了之后所有可能的答案；然后回溯到这一轮，i又选择了b，恰好nums[a]==nums[b]，那么以nums[b]为首的所有可能的答案，必然是之前以nums[a]为首的答案的子集，也就是说一定已经被之前探索a进行DFS时穷尽过了，如果再探索b得到的一定都是之前的重复答案。显然，我们应该在这个for循环的轮回里设置一个集合，凡是已经出现过的数字，都不用再基于它进行DFS了。

最后要注意的一个细节就是，不必搜索到nums的结尾再确定一个可行解加入results。只要curRes新增了一个元素，都满足题意，可以立即加入results.


[Leetcode Link](https://leetcode.com/problems/increasing-subsequences)