### 032.Longest-Valid-Parentheses

此题用stack来做非常巧妙.

我们用一个stack来做常规的符号匹配.我们可以得到每一个右括号与之对应的最近的左括号.这说明这对括号之间的距离都是合法,可以记录下来.但是这还不够,因为在这个左括号之前,可能已经有若干匹配并消除的括号对.比如```s="(()()"```，在处理消除第二对括号时，第一对括号已经消除了。这说明我们在将手头的右括号与栈顶的左括号消除后，需要再看一眼此时剩下的栈顶元素。从此时的栈顶元素对应的位置，到当前右括号的位置，这段区间都是合法的序列.

这就提示我们,在stack里存储的不是左右括号的字符,而是字符所在的位置.所以大致的算法如下:
```cpp
for (int i=0; i<s.size(); i++)
{
   if (s[i]=='(')
      Stack.push(i);
   else
   {
      Stack.pop();
      result = max(result, i-Stack.top());
   }
}
```
但是上述的算法有一个很大的问题.那就是读取Stack.top()时可能已经栈空,这可能是由于右括号过多的原因造成的,消除了全部的左括号.我们发现,出现这种情况时,说明这个右括号多余了,任何合法的字符串都不可能包括这个右括号了.所以我们就在Stack里添加这个位置,供后续的计算最大合法距离时作为起点使用.

同理,我们需要在最初始时,在Stack里添加-1,标记为起点.
```cpp
for (int i=0; i<s.size(); i++)
{
   if (s[i]=='(')
      Stack.push(i);
   else
   {
      Stack.pop();
      if (!Stack.empty())
        result = max(result, i-Stack.top());
      else
        Stack.push(i);
   }
}
```


[Leetcode Link](https://leetcode.com/problems/longest-valid-parentheses)
