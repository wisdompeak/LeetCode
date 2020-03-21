### 418.Sentence-Screen-Fitting

此题如果按照逐个单词去分析处理，结果会超时．更合理的方式是按照逐个ｃｏｌｓ的长度去处理．这里将sentence的所有单词用空格串联起来：
```cpp
    for (auto str:sentence)
        {
            if (str.size()>cols) return 0;
            s+= str+" ";
        }   
```      
注意，这里可以提前处理不合法的例子．

初始的字符idex是０，每处理一行，我们就把index+=cols，此时如果index落到了空格上，一切ＯＫ，说明至此的所有字符都可以放在一个row里面．如果没有落到空格上，说明某个单词没有写完就触碰了边界，这时候我们将index慢慢回退直至遇到了一个空格为止．

重复以上过程，当处理完rows行之后，看看此刻的index是length的多少倍，就说明能重复多少个字符串．


[Leetcode Link](https://leetcode.com/problems/sentence-screen-fitting)