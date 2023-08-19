### 2827.Number-of-Beautiful-Integers-in-the-Range

常规的数位计算的套路。开局就是`return helper(large) - helper(low-1)`，其中helper表示符合条件、且小于等于larger的数字的个数。

在实现helper时，我们用DFS的思想来逐个填充每个位置上的数字。在填充的过程中我们要监控两个量。第一个是奇数数位与偶数数位的个数之差，我们期望在填充完毕之后是0. 第二个是当前构造的数字对于k的模，我们期望在填充完毕之后也是0.

我们令`dfs(len, isSame, diff, r)`，表示还有len个数字需要填充（或者说当前需要填充倒数第len个位置），isSame表示之前已填充的数字是否与原数num的前缀贴合，diff表示当前奇数数位与偶数数位的个数之差，r表示已经构造的数字对于k的模。

我们考虑当前数字d的填充时，需要分两大类：

1. isSame是false，那么说明当前d可以从0填到9都没有任何顾虑（不会超过原数），故
```cpp
for (int d = 0; d <= 9; d++)
  ret += dfs(len-1, false, diff+((d%2==0)*2-1), (r*10+d)%k);
```

2. isSame是true，那么说明当前d可以从0填到`D = num[n-len]-1`都没有任何顾虑（不会超过原数），即
```cpp
int D = num[n-len];
for (int d = 0; d < D; d++)
  ret += dfs(len-1, false, diff+((d%2==0)*2-1), (r*10+d)%k);
```
但是d最大只能取到D，并且在下一个回合的过程中仍将标记`isSame=true`，即
```cpp
int D = num[n-len];
ret += dfs(len-1, true, diff+((D%2==0)*2-1), (r*10+D)%k);
```

最终边界条件是当len==0时，只有当`diff==0 && r==0`的时候才会返回`1`（因为此时已经将一个具体的数构造出来了），其余的时候我们构造出的是一个不符合条件的数，返回`0`.

最后我们加上记忆化。我们看到有四个参量`len,isSame,diff,r`，所以就定义memo[11][2][22][22]来存储各个dfs的结果，来避免重复的搜索。
