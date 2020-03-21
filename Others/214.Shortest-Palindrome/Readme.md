### 214.Shortest-Palindrome

此题的解法非常巧妙.首先,题意是试图将s分解为```s=A'AB```的形式,其中A'是A的逆序,求使得A'A最长的分解方式.

如果我们将s整体逆序写成r,那么```r=B'A'A```.可以发现s的前段和r的后端恰好都是```A'A```.此外,反过来考虑,已知r是s的逆序,并且r的尾端等于s的首端,那么这段相同的字符串一定是个palindrome,即A'A的形式.

有了以上两点证明,那么我们就只要找到最大的```i```,使得```s[0:i]==r[len(s)-i:]```即可.



[Leetcode Link](https://leetcode.com/problems/shortest-palindrome)