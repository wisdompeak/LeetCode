### 1320.Minimum-Distance-to-Type-a-Word-Using-Two-Fingers

#### 解法1：
一个比较容易想到的方法就是将两个手指所处的位置作为状态。定义dp[k][i][j]表示第k轮的时候，左手在i、右手在j的min distance。注意，左手和右手必须至少有一个是在ch=word[k]上，否则这个dp状态就是无意义。

对于从第k-1轮到第k轮的状态转移过程，我们可以分为两类途径：一个是移动左手使之到ch上，得到新状态dp[k][ch][i]；另一个是移动右手使之到ch上，，得到新状态dp[k][i][ch]。其中i表示另一个手指的位置，可以是任意的地方。综上，我们有：
```cpp
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++)
                {
                    dp[k][i][ch] = min( dp[k][i][ch], dp[k-1][i][j] + dist(j, ch)); 
                }
            
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++)
                {
                    dp[k][ch][i] = min( dp[k][ch][i], dp[k-1][j][i] + dist(j, ch)); 
                }
```
最终的结果是在所有的dp[n-1][ch][i]和dp[n-1][i][ch]找最小的值。

#### 解法2：
上面的解法最大的缺点是dp[k][i][j]的存储效率不高，当i和j都不为ch=word[k]时，都是无意义的状态变量。也就是说，每一轮时的ch都是可以确定且必须存在的，我们因此可以省下这一个维度的空间。重新定义dp[k][i]：表示第k轮，（除了处于ch的那根手指）另外一根手指落在位置i时，需要的minimum distance.

这个时候我们思考如何更新dp[k][i].第k-1轮时，一个手指在prev=word[k-1]，另一个手指在x；第k轮时，一个手指在cur=word[k]，另一个手指在i. 同样有两种状态转移的可能：

第一种，通过prev转移到cur，那么就要求x必须等于i。因此有 dp[k][i] = dp[k-1][i]+dis(prev,cur)。

第二种，通过prev转移到i，那么就要求x等于cur。因此有 dp[k][i] = dp[k-1][cur]+dis(prev,i)。

所以dp[k][i]就是上述两种方法中的较小值。

最终的结果是在所有的dp[n-1][i]中找最小的值。这是因为我们一定已经保证了有一个手指位于word.back()。








[Leetcode Link](https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers)