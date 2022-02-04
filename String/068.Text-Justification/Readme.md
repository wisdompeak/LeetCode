### 068.Text-Justification

这是一道比较复杂的模拟题，需要耐心地做。

首先我们要做的是找出每一行需要打印多少单词。假设某行开始，我们需要从words[i]开始打印直到到words[j]为止，确定这个[i:j]的区间需要满足的条件是：words[i:j]的字符长度加上(j-i)个空格，必须恰好小于等于maxWidth。然后我们就可以调用一个自定义的```printLine```的函数来控制如何在maxWidth里面打印这么多单词。唯一例外的是，如果发现j是最后一个单词，那么需要特殊处理一下，空格不需要在单词之间平均分布。

接下来我们写函数```string printLine(i,j)```. 我们需要先计算空格总数```m = maxWidth - words[i:j]的长度和```，试图均分给(j-i)个间隙，可以得到基础间隙大小是```s = m/(j-i)```. 此时我们可能存留有```k = m-s*(j-i)```个空格需要分配，根据规则这些空格会给前k个间隙的位置上每个加1. 代码大致是
```cpp
        for (int i=a; i<a+k; i++)    
            ret += words[i] + addspace(s+1);        
        for (int i=a+k; i<b; i++)        
            ret += words[i] + addspace(s);        
        ret+=words[b];              
```        
