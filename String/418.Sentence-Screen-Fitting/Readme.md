### 418.Sentence-Screen-Fitting

此题如果按照逐个单词去填充，那么如果单词长度都特别短的话，想要填充完rows x cols这么多位置就会TLE．本题更合理的方式是以cols的长度去处理。首先将sentence的所有单词用空格串联起来记做str：
```cpp
    for (auto str:sentence)
        {
            if (str.size()>cols) return 0;
            s+= str+" ";
        }   
```      
注意，这里可以提前处理不合法的例子．

我们接下来的任务就是在一段```xxx xxx xx xxxx xx x xxxx ```里面试图以每cols的宽度去插板，要求板子只能插在空格里，不能分割任何单词本身。特别注意，最后我们特地留有一个空格，这是为了将前一个str与下一个str之间区分开来。

具体的做法是，初始的指针index指向0，每处理一行，我们就把index+=cols，此时如果index落到了空格上，说明至此的所有字符都可以放在一个row里面，然后index指向空格后的第一个字符。如果没有落到空格上，说明某个单词没有写完就触碰了边界，这时候我们将index慢慢回退直至遇到了一个空格为止。

注意到指针wrap的情况，所以我们对于index的处理永远都是考虑它对str长度的取余。

重复以上过程，当处理完rows行之后，看看此刻的index是str长度的多少倍，就说明能重复多少个字符串．

[Leetcode Link](https://leetcode.com/problems/sentence-screen-fitting)
