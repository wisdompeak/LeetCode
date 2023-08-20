### 2801.Count-Stepping-Numbers-in-Range

首先依据套路转化为前缀之差的形式：`return helper(high) - helper(low) + check(low)`. 其中helper(num)表示求[1,num]区间内符合要求的数的个数。

我们用dfs的方法来这个填充每一位。设计`dfs(len, prev, isSame)`表示在当前“状态”最终会有多少个合法的数字，其中len表示还有多少位需要填充，prev表示上一位填充的数字是什么，isSame表示之前填充的所有数字是否与num的前缀贴合。

1. 如果isSame==false，那么只要`prev+1<=9`，那么就可以在当前位填充prev+1；只要`prev-1>=0`，那么就可以在当前位填充prev-1. 递归函数里的isSame都是false。

2. 如果isSame==true，令当前位置上num的数字是D，那么只要`prev+1<D` ，那么就可以在当前位填充prev+1；只要`prev-1>=0 && prev-1<D`，那么就可以在当前位填充prev-1. 递归函数里的isSame都是false。此外，如果`prev+1==D`，位置也可以填充prev+1，只不过后续的递归函数里isSame=true。同理，如果`prev-1==D`，位置也可以填充prev-1，只不过后续的递归函数里isSame=true。

在helper函数里，需要枚举数的长度、起始位置的填充（d只能从1开始选择），调用各自的dfs函数，并将结果相加。

最后别忘了记忆化数组`memo[len][prev][isSame]`来减少重复计算。
