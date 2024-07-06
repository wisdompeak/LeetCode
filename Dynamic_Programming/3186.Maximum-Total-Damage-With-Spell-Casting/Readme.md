### 3186.Maximum-Total-Damage-With-Spell-Casting

这非常类似一个house robber的问题。我们将所有的spell按照power的distinct value按从小到大排序，定义dp[i]表示从前i件spell里选取所能构成的最大和，其中题意要求不能选取power值差距在2以内的spell。特别注意，dp[i]不一定要求必须取第i种spell。

当我们考察spell[i]的时候，我们可以不取第i种spell，这样的话就是dp[i]=dp[i-1].

如果取第i种spell，那么保底就是仅取第i种药水的收益。其次我们查看spell[i-1]是否与spell[i]的差值在2之外，如果是的话，那么dp[i]就可以在dp[i-1]的基础上加上所有属于spell[i]的power。如果不是的话，我们往前查看spell[i-2]与spell[i]的差值是否在2之外，如果是的话，那么dp[i]就可以在dp[i-2]的基础上加上所有属于spell[i]的power。如果再不是的话，那么dp[i]可以直接在dp[i-3]的基础上加上所有属于spell[i]的power，这是因为spell数值彼此不同，spell[i-3]和spell[i]的差值必然大于2.

最终答案返回dp[n-1]即可。
