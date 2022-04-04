### 2223.Sum-of-Scores-of-Built-Strings

#### 解法1：扩展KMP
本题乍看像KMP，但其实不是。KMP给出的dp[i]表示以s[i]结尾的最长后缀，使得其等于s的前缀。而本题需要求的是，以s[i]开头的最长前缀，使得其等于s的前缀。这其实叫做扩展KMP。相关的资料见[OI Wiki](https://oi-wiki.org/string/z-func/)

#### 解法2：Rolling Hash + Binary Search
另一种更接地气的做法是Rolling Hash。对于任意的位置i，我们想查看子串s[i:n-1]与s相同的最长前缀，不妨暴力地二分尝试。即猜测一个长度len，查看s[i:i+len-1]是否与s[0,len-1]相同。但是此处显然不会无脑地逐个字符去对比，我们只需要用o(1)时间比较这两段区间的Hash值。

那么怎么得到任意一段区间的Hash值呢？这就类似于前缀和的思想。我们用hashes[i]表示将字符串前缀s[0:i]哈希为一个26进制数的结果。显然我们可以用o(n)提前预处理，得到所有的hashes[i]。于是对于任意一个区间[i:j]，他们对应的hash值就是```hashes[j] - hashes[i-1]*26^(j-i)```.

Hash的过程中显然会有数值溢出的问题，通常情况下我们要设计MOD在计算的过程中不停地取余。一个取巧的方法就是用无符号长整形unsigned long long，利用自然溢出的特性来省去手工取余。用ULL的另一个好处就是区间的hash值计算里永远不会出现负数，保持了一致性。
