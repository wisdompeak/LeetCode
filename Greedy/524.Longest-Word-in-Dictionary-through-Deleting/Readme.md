### 524.Longest-Word-in-Dictionary-through-Deleting

此题等同于```792.Number-of-Matching-Subsequences```. 我们预处理得到next[i][ch]，表示S中位置i右边第一个出现字符ch的位置。这样对于每一个单词word，假设长度为n，我们只需要用o(n)的时间就可以找到全部字符在s中的对应位置。具体做法是，令初始i=0，然后遍历word所有的ch，不断地更新```i = next[i][ch]```。如果某个```next[i][ch]==-1```，那么就说明word不是s的subsequence。
