### 844.Backspace-String-Compare

此题的考点是用o(n)时间和o(1)空间．这就提示我们做in-place的修改．

我们可以尝试用双指针的方法，将有效的字符都移动到字符串的前面去。具体的做法是快指针j扫每个元素，如果遇到了正常的字符，则str[i]=str[j]，同时慢指针i自增1。如果遇到了退格键，那么将慢指针i退一个即可。最终i指针的位置就代表了这个字符串最终有多长。


[Leetcode Link](https://leetcode.com/problems/backspace-string-compare)
