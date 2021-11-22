### 2052.Minimum-Cost-to-Separate-Sentence-Into-Rows

首先计算每个单词的长度，放入数组nums. 

令dp[i]表前i个单词所需要的最小cost是多少。显然我们会考虑i所在的行的第一个单词j的选择，这样就有```dp[i] = dp[j-1] +  cost(k, len[j:i], (i-j)) ```，其中len[j:i]表示第j个到第i个单词的总词长，(i-j)表示该行需要的空格长度。其中我们令j从i开始，从后往前遍历，直至不满足```len[j:i]+(i-j)<=k```

特别注意，本题中的cost不包含最后一行。因此我们在计算i=n的时候，答案就是此时所有合法dp[j-1]中的最小值。
