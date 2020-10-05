### 1611.Minimum-One-Bit-Operations-to-Make-Integers-Zero

#### 解法1 递归
我们读懂题意之后，尝试自己来挑一个数试一试。比如说1xxxxx，我们会发现要使得最高的1变成0，似乎只能通过第二条规则。那么第二条规则需要我们干什么事情呢？其实共有三步：
```
1(xxxxx) -> 1(10000) -> 0(10000) -> 0(00000)
```
第一步，将除最高位之外的xxxxx转化为10000;   
第二步，于是接下来我们根据规则2，可以将最高位变成0;   
第三步，解决完最高位，我们就可以递归处理剩余的数字，也就是将10000转化为00000

对于第二步，这是规则2的操作。对于第三步，其实就是递归调用原来的函数minimumOneBitOperations。但是对于第一步，似乎是一个我们未见过的变换，那么我们暂时将其定义为helper(n)，并仔细分析一下它。

helper(n)其实要做的事情，就是将参数n=xxxxx转化为相同位数的bit串：最高位是1，其他位是0. 这时候一个显而易见的发现就是：如果n的最高位也是1的话（即n=1xxxx），那么helper(n)的本质就是将剩下的xxxx转化为0000，咦，这不就是minimumOneBitOperations要做的事情吗，递归处理不就OK了？

接下来我们就自然会考虑另外一种情况，如果n的最高位是0（即n=0xxxx）,那么helper(n)的作用是将0xxxx转化为10000。这时候为了能将最高位从0变成1，我们又不得不再次使用规则2，再三步走：
```
0(xxxx) -> 1(1000) -> 0(1000) -> 0(0000)
```
这三步走是不是很熟悉？第一步就是helper(xxxx)，第二步就是规则2的操作，第三步就是minimumOneBitOperations(1000)。

分析到这里，我们已经可以把任意minimumOneBitOperations(n)的转化过程分析完了：这些分解可以拆成反复递归调用minimumOneBitOperations和helper，作用在更短的字符串上。只要合理地设计好这两个递归函数的边界条件，那么递归层层返回后的结果就是答案。当然，实际操作过程中我们需要记忆化的帮助来减少计算量。

最后总结一下：
```
minimumOneBitOperations(1xxxxx) = helper(xxxxx)+1+minimumOneBitOperations(10000)
helper(xxxxx) = minimumOneBitOperations(xxxx), if the highest bit is 0
                helper(xxxx)+1+minimumOneBitOperations(1000), if the highest bit is 1
```

#### 解法2 格雷码
如果我们亲自拆解一个数字来试一下。当n为6时，最优的变化步骤是 110->010->011->001->000. 我们能观察到什么？每相邻两次变化，只有一个bit发生了变化！这就是格雷码序列！所谓的格雷码序列，就是对于n bit的二进制数而言，我们令00...00为序列的第一个数，可以构建一个长度为2^n的序列，序列中每相邻的两个数字只相差一个bit（包括序列的最后一个与序列的第一个）。

关于格雷码的生成方法，可以参见```089. Gray Code```的解答。我们有格雷码的通项公式
```cpp
for (int i=0; i<(1<<n); i++)
    gray[i] = i^(i>>1);
```
在本题中，我们只要找到n在格雷码序列中的位置（即对应的索引i），就可以判定它与0之间的距离。那么如何从gray[i]反求出i呢？其实很简单，假设i的二进制表达是 abcdef，那么
```
  abcdef
^ 0abcde
-------
  xxxxxx (binary string of n)
```
很显然，从高位开始可以逐位破解abcdef.



