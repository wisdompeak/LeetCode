### 1653.Minimum-Deletions-to-Make-String-Balanced

注意到最终变换后的形式是"aaaa....bbbbb"，关键点就是这个ab的分界处。所以我们遍历这个分界点：假设最终状态是[0:i]都变成'a'，[i+1:n-1]都变成'b'，那么所需要的操作数，就是[0:i]中'b'的个数加上[i+1:n-1]中'a'的个数。对于这两个量，我们可以提前two pass预处理以前缀和/后缀和数组的形式存下来，即```ret[i] = pre[i]+suf[i+1]```。

本题有两个corner cases，分别是把所有的字母变成a或者b，对应的是pre[n-1]和suf[0]，这需要单独考察。
