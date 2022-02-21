### 2182.Construct-String-With-Repeat-Limit

非常直观的贪心策略。所有的字母统计频次之后，按照字典序从大到小放入pq里。有这么几种情况：
1. 最大的字母少于或者等于repeatLimit个，那么就将其全部取出。
2. 最大的字母有多于repeatLimit个，那么就取出repeatLimit个，同时再取次大的字母一个。将最大和次大字母再塞入pq中（如果还有的话）。
3. 最大的字母有多于repeatLimit个，那么就取出repeatLimit个，此时pq里没有次大的字母，就直接返回。
