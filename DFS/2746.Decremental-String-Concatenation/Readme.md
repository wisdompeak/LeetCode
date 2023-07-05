### 2746.Decremental-String-Concatenation

考虑到n的数量不大，估计可以暴力搜索。顺次遍历每一个单词，我们只需要考察将其加在已有str的前面还是后面两种决策。这看上去复杂度会有2^50，但是我们事实我们并不需要枚举这么多状态。假设前两个单词{abc,aec}，那么这两个单词的拼接方式对于后续的选择而言没有不同，因为都是`a****c`。我们能否压缩长度的关键，其实只需要关注str的第一个和最后一个字符即可。于是我们实际需要枚举的状态最多只有50*26*26种。

由此我们可以定义递归函数`int dfs(int i, int start, int end)`，表示the minimum length to be added if we construct the first i words with start & end. 也就是说，当前i个单词构造出来的str以start开头、end结尾时，我们需要考虑如何使用words[i]：很明显两种方案，放在前面或者放在后面。此时我们就可以根据start/end与words[i]的首尾字符，进行递归处理：
```cpp
int a = words[i][0]-'a', b = words[i].back()-'a';
// 放后面
if (end==a)
    ret = min(ret, len-1 + dfs(i+1, start, b, words));
else
    ret = min(ret, len + dfs(i+1, start, b, words));

// 放前面
if (start==b)
    ret = min(ret, len-1 + dfs(i+1, a, end, words));
else
    ret = min(ret, len + dfs(i+1, a, end, words));
```
最终的答案就是初始调用的`words[0].size() + dfs(1, words[0][0], words[0].back())`，因为对于words[0]我们只有唯一的构造形式。

另外，我们必然要用记忆化来避免相同参数的dfs重复调用。
