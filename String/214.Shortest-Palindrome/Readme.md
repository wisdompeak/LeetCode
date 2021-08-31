### 214.Shortest-Palindrome

#### 解法1：KMP
此题的解法非常巧妙.首先,题意是试图将s分解为```s=A'AB```的形式,其中A'是A的逆序,求使得A'A最长的分解方式.

如果我们将s整体逆序写成r,那么```r=B'A'A```.可以发现s的前段和r的后端恰好都是```A'A```.此外,反过来考虑,已知r是s的逆序,并且r的尾端等于s的首端,那么这段相同的字符串一定是个palindrome,即A'A的形式.

有了以上两点证明,那么我们就只要找到最大的```i```,使得```s[0:i]==r[len(r)-i:]```，即在r中找到最长的后缀，使得其等于s的前缀。实现这个可以有两种方法：1. 暴力尝试这个长度。2. 类似KMP中求后缀数组的方法，计算数组r的suf[i]，即r中截止位置i的最长后缀字符串使得恰好是s的前缀字符串。

最终suf[n-1]就是A'A的最大长度。因此B = s.substr(len). 返回的答案就是ret = B'+s.

### 解法2：Manacher
本题的本质就是在s中找一个最长的、起点在左端点的回文串。然后将s除去回文串的后端复制、翻转并拼接在原s串的前端，就是最优的答案。

所以此题的本质就是Manacher的模板题```005.Longest-Palindromic-Substring```，求出每个位置作为中心能够构造的最长回文串，查看这个回文串是否能抵达s的最左端，是的话就记录下这个回文串的长度L。输出的答案是：
```cpp
string temp = s.substr(R);
reverse(temp.begin(), temp.end());
return temp+s;
```

[Leetcode Link](https://leetcode.com/problems/shortest-palindrome)
