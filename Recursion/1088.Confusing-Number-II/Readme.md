### 1088.Confusing-Number-II

这题和902.Numbers-At-Most-N-Given-Digit-Set很像，只能够用0,1,6,8,9这五个数字嘛。

最基本的方法，就是用递归遍历所有可能生成的数（by不断增长位数），每一步都判断是否小于等于N并且是否confusing number，满足条件就计数器加一。当然这个方法非常低效，在902是无法AC的，但是在这里也能够过了，大概beat 20%。

有一种稍微优化点的方案，就是对于digit位数小于N的confusing number，我们不需要一一列举，而是用数学方法直接表达。举个例子，当N是六位数时，所有五位数的confusing number都不会大于N，也就不用考虑这个约束。那么如何求长度为len的confusing number有多少个呢？

首先，我们知道confusing number只能用0,1,6,8,9这五个数字组数。先考虑给定这个digit集合能组成多少个长度为len的数？显然答案是```4*pow(5,len-1)```，其中4是考虑到了高位首位不能为零。

然后我们考虑在上述这些数中间有多少non-confusing number呢？Non-confusing number的定义就是翻转之后和原来的数字一样，也就是说，相对中间位置对称的两个digit需要是翻转对称的（也就是1->1,6->9,8->8,9->6,0->0），并且如果长度是奇数那么中间一个digit与自己翻转堆成（也就是1->1,8->8,0->0）.所以对于长度为len的数，non-confusing number的个数的计算方法：
```cpp
        if (len%2==0)        
            return 4*pow(5,len/2-1);
        else
            return 4*pow(5,len/2-1)*3;
```
同理，4表示高位第一位不能是0，所以是四种选择。3表示长度是奇数时，中间一个digit的选择只有三种。其他位置（从高位第一位到中间一位）的选择是五种。len/2的操作是因为，对于non-confusing number，只要确定了前一般长度的digit，后一半的digit也就确定了。

所以对于长度为len的confusing number，就是上面计算得到的两个结果之差。同理，所有小于N的长度的len，我们可以这样用数学方法计算长度为len的confusing number的数目。

至于len等于N的长度的情况，我们依然可以采用DFS（也就是递归）的笨办法。最终version 2的时间复杂度能够beat 50%.

当然，还可以有更多的优化，基本思路就是参照902：DFS只贴着N的大小走，如果选取某一位的digit比N对应的那位要小，则摆脱了必须小于N的约束，剩下的digit的组合数目就可以用数学表达式来写。不过感觉有些复杂，我就没有继续深入研究下去。


[Leetcode Link](https://leetcode.com/problems/confusing-number-ii)