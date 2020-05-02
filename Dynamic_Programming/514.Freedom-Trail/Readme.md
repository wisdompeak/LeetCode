### 514.Freedom-Trail

我们知道第i次操作的时候，一定是将key[i]这个字符移动到12点位置，并且我们还知道，在操作之前，处在12点位置的字符一定是key[i-1].

于是有两个问题：当ring存在多个重复的字符时，我们移动哪个key[i]到12点位置？另外，已经处于12点位置的那个key[i-1]又是ring上面的哪一个？

其实我们把所有的“最优子问题”都带上这两个参数就可以轻松来做动态规划了。

我们定义dp[i][cur_pos]表示第i轮我们要将ring上的cur_pos这个字符移动到12点位置，所对应的最优解（也就是最少转动次数）。显然这个cur_pos一定会是对应着key[i]。那么它的前驱状态是什么？显然是dp[i-1][prev_pos]，表示前一轮的时候我们是把ring上的prev_pos这个字符移动在了12点位置；同理，这个prev_pos一定会是对应着key[i-1]。

于是这个问题就变成了从prev_pos对着12点，转动到cur_pos对着12点，最少需要转动几步？无非就是顺时针转或逆时针转而以。于是
```cpp
dp[i][cur_pos] = dp[i-1][prev_pos]+min( abs(prev_pos-cur_pos), ring.size()-abs(prev_pos-cur_pos) )
```
特别注意，这样的prev_pos会有多个，我们需要取它们之中的最小值。
