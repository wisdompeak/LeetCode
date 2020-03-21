### 948.Bag-of-Tokens

本题的大体思路是，我们先将tokens排序，优先用手头的P去收购面值最小的tokens[i]，等到手头的P不够用了怎么办？我们将当前手头最小的token[i]兑换成1个point再去兑换面值最大的token[j]，这样空手套白狼，就将手头的P又凭空增加了token[j]．但代价有两个：第一是我们少了一个point；第二是我们失去未来收购面值最大的token[j]的机会．

所以，总体的最优策略已经出来了．那就是按照上面的方法，手头的Ｐ按从小到大能收购多少token那就收购，不能收购就卖掉面值减去1分（卖掉最小的token）换面值最大的，增值手头的Ｐ．然后重复上述过程．整个流程中，手头曾持有最多的token的数量，就是答案．

核心的代码如下：
```cpp
        while (i<=j)  // 保证手头待买入的i必须在待替换的j之前
        {
            if (P>=tokens[i])   // 仍然有钱买入
            {
                P-=tokens[i];
                i++;
                points++;
                result = max(result,points);
            }
            else if (points>0)  // 没钱买了，但是仍有分可以卖
            {
                points--;
                P+=tokens[j];
                j--;
            }
            else                // 既不能买，也不能卖，策略结束
                break;
        }
```


[Leetcode Link](https://leetcode.com/problems/bag-of-tokens)