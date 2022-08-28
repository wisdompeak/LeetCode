### 942.DI-String-Match

此题完全可以用`2375.Construct-Smallest-Number-From-DI-String`一样的方法，给出字典序最小的permutation。

基本思想是将s的开头加上一个“I”，将s切分为若干"IDD..D"的pattern，每个pattern对应的是一段单调递减的序列。保证序列与序列之间不重合即可。
