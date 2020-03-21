### 1105.Filling-Bookcase-Shelves

这道题的突破点就在于你是否能想到用动态规划。贪心法啥的可能是个误区。

我们处理第i本书的时候，得考虑它之前的放在同一层的书可能有多少？我们可以往前一一遍历过来，直至同一层的书宽度超过了shelf_width的限制为止。注意，遍历的过程中，我们认为它们都是在同一层的，所以这一层的高度就是这些书高度的最大值maxCurHeight。假如我们认为books[i]到books[j]都是属于同一层的，那么截止到第i本书整体占据的绝对高度，就是截止到第j-1本书整体占据的绝对高度（也就是上一层的高度）加上这一层当前的maxCurHeight。

所以dp[i]的定义就是，将第i本书作为当层最后一本书时，此时整体的书架高度。状态转移方程就是：
```
dp[i] = min {dp[j-1] + max(books[j][1]，...,books[i][1]) }  for j = i, i-1, ...
```


[Leetcode Link](https://leetcode.com/problems/filling-bookcase-shelves)