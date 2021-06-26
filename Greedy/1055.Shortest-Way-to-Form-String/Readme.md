### 1055.Shortest-Way-to-Form-String

本题的最优策略就是贪心。我们总试图在source里找到一个subsequence去匹配target的前几个字符。匹配完若干个字符后，就从头再在source里找subsequence去匹配target的接下来的几个字符。直至把target全部匹配完，或者source完全无法提供匹配。

这样的解法有多种多样，但最优的写法类似792，采用状态机可以做到o(N)级别。

我们预先用o(26N)的时间来处理source。我们构建next[i][k]表示在source的第i个位置的下一个字符k在哪个位置。注意为了方便起见，我们将source调整为1-index。如果i的位置后面没有字符k，则令next[i][k]=-1.

接下来我们遍历target，用i表示我们在source里寻找target的第i个字符，用j表示我们当前位于source里的位置。假设我们在source的位置j找到了target[i-1]，那么target[i]就应该位于next[j][target[i]]。于是接下来我们需要更新
```
j = next[j][target[i]];
```
注意，如果此时j=-1，表示我们已经搜完了一遍source但是没有找到匹配target[i]，此时需要重置j=0再在source中搜一轮。如果j!=-1，那么说明target[i]已经找到，可以i+=1.

最终统计我们在source里面搜过了几轮，就是需要几个source的subsequence来拼接成target。
