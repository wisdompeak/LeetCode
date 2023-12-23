### 2950.Number-of-Divisible-Substrings

此题有精彩的o(N)解法。

对于以j为结尾的substring，我们希望找到位置i<j，使得`(presum[j]-presum[i]) % (j-i) == 0`，即存在整数k，使得`(presum[j]-presum[i]) = (j-i)*k`，变化一下得到`presum[j]-k*j = presum[i]-k*i`. 

此题的关键在于我们发现，k的范围是1到9. 这是因为每个字符能贡献的数字只能是1~9，故必然有`(presum[j]-presum[i]) / (j-i) <= 9`. 

由此，对于任意的j，我们只需要遍历k，就可以得到一个key: `presum[j]-k*j`，只需要建立一个Hash表，查看在j之前的index里是否存在相同的key即可。
