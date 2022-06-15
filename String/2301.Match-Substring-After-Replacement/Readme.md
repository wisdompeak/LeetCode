### 2301.Match-Substring-After-Replacement

#### 解法1：暴力
本题暴力查验字符串匹配，时间是o(N^2)，有AC的可能。

#### 解法2：KMP
本题的本质其实就是在一个字符串中查找匹配的子串。最直观的高效解法就是KMP。我们只需要略微修改KMP算法中关于“两个字符相等”的定义。

在KMP的主函数中，定义一个新的```equal(char a, char b)```. 当两个字符相等，或者sub的字符可以映射到s的字符中时，就返回true。

在KMP的preprocessing函数中，定义一个新的```equal2(char a, char b)```. 当两个字符相等，或者这两个字符都可以映射到同一个字符时，就返回true。

更新：这道题不存在正确的KMP解法，敬请注意。
