### 2538.Difference-Between-Maximum-and-Minimum-Price-Sum

因为选定了root之后的Min Price必然对应的就是root节点本身，所以所谓的“Difference-Between-Maximum-and-Minimum-Price-Sum”就是从root的邻接节点开始找一条最大路径。既然是求最大路径，必然我们会将另一个端点取到某个叶子节点。综上，本题的本质是在树里找一条最大路径，一端是叶子节点，另一端是非叶子节点（这样它必然有一个邻接节点可以作为root）。

在树里找最大路径，最常见的方法就是遍历“拐点”。我们以任意一个节点为根来观察图，树里的任何一条路径都有一个“拐点”。我们就是需要给这个拐点找两个“下垂”的分支路径，一个延伸到叶子节点，另一个不能包括叶子节点。当然，还有第三种情况，就是“拐点”本身就是一个端点，那样的话我们只需要找一条“下垂”的分支路径，该路径不能延伸到叶子节点。

我们可以提前用递归预处理整棵树。对于每个节点，我们可以计算出该节点向下到非叶子节点的最大路径（记做sum1），以及该节点向下到叶子节点的最大路径（记做sum2）。显然，对于sum1而言，只需要在递归的时候不加入叶子节点即可。代码如下：
```cpp
    void dfs(int cur, int prev, vector<int>& price)
    {
        if (当前节点cur是叶子节点)
        {
            sum1[cur] = 0;
            sum2[cur] = price[cur];
            return;            
        }
        
        LL maxSum1 = 0, maxSum2 = 0;
        for (int nxt: next[cur])
        {
            if (nxt==prev) continue;
            dfs(nxt, cur, price);
            maxSum1 = max(maxSum1, sum1[nxt]);
            maxSum2 = max(maxSum2, sum2[nxt]);
        }
        
        sum1[cur] = maxSum1 + price[cur];
        sum2[cur] = maxSum2 + price[cur];
    }
```

然后我们第二遍递归整棵树，对于每个节点cur，有两种构造路径的情况：
1. 该节点就是路径的端点，于是路径的值就是`sum1[cur]`
2. 该节点是拐点，且至少有两条向下的路径，那么我们在cur的所有孩子里找最大的sum1和最大的sum2，这两段拼接起来即可。但是有可能这两段向下的路径对应的是同一条支路。这样的话，我们需要选取“最大的sum1和次大的sum2”，以及“次大的sum1和最大的sum2”。

在以上三个答案中，我们挑选最大的一个，作为以cur为拐点的最大路径。最终遍历所有的节点，取全局最大值。

特别注意，当n=1时，全图只有一个节点，根和叶子节点重合，`if (当前节点cur是叶子节点)`的代码需要格外小心。


