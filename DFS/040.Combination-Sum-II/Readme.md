### 040.Combination-Sum-II

本题和LC 039非常类似。但有一个非常重要的情况需要考虑。假设target=5，candidates={3,1,1}，那么按照传统的DFS方法，会搜索到两个组合{3,1}，这两个组合中的1其实对应着的是candidates里面不同的元素。如何高效地去除这种重复的情况呢？

我们先将candidates排序。然后规定：凡是相同的元素，我们只能按先后次序连续取，而不能跳着取。比如上面的例子，我们如果需要取一个1，那么就取第一个1.如果需要取两个1，那么就取前两个1.以此类推。

那么如何在代码中高效地实现这个过滤呢？非常简单。
```cpp
for (int i=idx; i<candidates.size(); i++)
{
  if (i>idx && candidates[i]==candidates[i-1])
    continue;
  
  // do you recursion here
}
```
这段代码的语境是，在这一轮中，我们需要在```candidates[idx:end]```中间选取一个数加入comb。如果我们选中了candidates[i]，那么说明candidates[i-1]就没有被选中。此时如果发现```candidates[i]==candidates[i-1]```，则意味着相同的元素我们“跳着”选取了，这是上面指定的规则所不允许的，就可以终止。

当然有一个特例，如果i选中的就是candidates[idx]，那是可以豁免的。这是因为上一轮我们选中的就是candidates[idx-1]。这样即使```candidates[i]==candidates[i-1]```，其实恰好说明我们就是顺着连续选取地这个元素。

这个处理技巧在DFS的题目中会经常遇到，需要能够熟练掌握。


[Leetcode Link](https://leetcode.com/problems/combination-sum-ii)