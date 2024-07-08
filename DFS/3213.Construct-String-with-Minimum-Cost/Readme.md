### 3213.Construct-String-with-Minimum-Cost

此题似乎并没有什么特别好的办法。似乎只能暴力搜索，穷举target里的每一段是否适配某些word。

为了高效判定一段字符串是否出现在某些给定的words里，显然我们会先将所有word构造成一棵字典树。将word加入字典树的时候，记得在结尾节点附上该word的cost。如果有多个相同的word，我们只保留最小的cost。

我们定义dfs(i)表示target从位置i开始到结尾这段后缀成功分解所能得到的最小代价。我们就有：
```cpp
dfs(i) = min{cost of target[i:j] + dfs(j+1)};  for (int j=i; j<n; j++)
```
当我们移动指针j的时候，同时根据taget[j]在字典树里游走。如果游走到一个cost非-1的节点，那么意味着target[i:j]对应着一个word，我们就可以递归处理dfs(j+1)即可。

此外，dfs记得要配合记忆化一起使用。
