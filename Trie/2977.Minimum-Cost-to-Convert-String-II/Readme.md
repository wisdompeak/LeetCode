### 2977.Minimum-Cost-to-Convert-String-II

本题和`2976. Minimum Cost to Convert String I`类似的思路，只不过2976里构造的最短路径图的顶点是“字母”，而本题里图的顶点是“字符串”。我们用Floyd可以容易求出“original->changed”里出现过任意两个字符串之间的最小代价，将字符串离散化后（用hash表记录每种字符串的序号），记录在数组d[][]里。

然后考虑从source到target的转化，很明显这是一个动态规划。对于前i个字符的前缀而言，成功转化的关键在于i所在的字符串转化是什么？我们需要找到一个位置j<i，使得source[j:i]到target[j:i]的转化是在数组d里存在的。这样就有
```cpp
for (int i=0; i<source.size(); i++)
{
    if (source[i]==target[i))
        dp[i] = dp[i-1];
    for (int j=0; j<=i; j++)
    {
       if (d[source[j:i]][target[j:i]] 存在)
        dp[i] = min(dp[i], dp[j-1] + d[source[j:i]][target[j:i]]);          
    }
}
```
表面上看这个动态规划是o(N^2)的复杂度。但是其中要读取`source[j:i]`和`[target[j:i]`，通过Hash表找到对应的离散化序号从而查询d[][]，这个过程其实又增加了一层线性的复杂度。故会TLE。

解决的方法是将图里所有作为顶点的字符串逆序存入一个字典树里，字典树里的每一个字符串的最后一个节点标记离散化的序号idx。这样在上述动态规划的过程中，第二层循环，我们可以将j从i往0逆序遍历，遍历的过程中，同时在字典树里从上往下游走，如果失配的话，就直接中断j的循环。如果发现游走到字典树里的某个节点其idx标记不为-1，那说明存在source[j:i]是在最短路径数组d里存在的。同理，我们也可以高效地求出target[j:i]的离散化序号。这样，这个DP的复杂度就是真正的o(N^2)，不需要反复读取区间字符串。

