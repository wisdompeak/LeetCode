### 2014.Longest-Subsequence-Repeated-k-Times

本题其实并没有特别高明的算法，就是“暴力”枚举可能的repeated subsequence，然后检验该子序列能否在s中重复k次。显然对于“检验”的操作，复杂度就是o(n)=16000，那么枚举repeated subsequence的复杂度是多少呢？

注意到本题的约束条件```n < k*8```. 这说明了两点：首先，repeated subsequence的长度不超过7，否则重复k次之后会有```n>=len(subsequence)*k>=8*k```推出矛盾。其次，s里面频次大于等于k的字符种类不应该超过7，否则也会有```n>=k*8```推出矛盾。这两个推论告诉我们，repeated subsequence的构造并没有那么复杂，它最长只有7位，并且字符的种类不会超过7种。所以repeated subsequence的可能性最多就是7^7+7^6+7^5...= 7^8 = 5e6。

按照上面的分析，共有5e6种可能的subsequence，每次检验需要1.6e4，总的时间复杂度依然达到了1e10数量级。我们只能寄希望于剪枝，降低subsequence的种类数目。其中一种方法就是，如果我们发现一个较短的subsequence不符合条件（即无法重复k次依然是s的子序列），那么任何在此基础上append任何字符也都不会符合条件。所以这就提醒我们“暴力”枚举repeated subsequence可以采用从短的序列逐渐生成更长序列的方法，一旦检验发现不合条件，就可以终止这个支路。
