### 1815.Maximum-Number-of-Groups-Getting-Fresh-Donuts

我们从数据的规模上来看，应该猜测这是一个NP问题，解法应该是基于搜索。因为groups的总数最多只有30，暴力搜索也许可行？于是我们可以写出第一个版本：
```cpp
    int dfs(vector<int>&count, int presum, int i)
    {
        if (i==n) 
            return 0;

        int bonus = (presum % b == 0);
        int ret = 0;
        for (int j=0; j<b; j++)
        {
            if (count[j]==0) continue;
            count[j]--;
            ret = max(ret, dfs(count, (presum+j) % b, i+1));
            count[j]++;
        }

        return ret + bonus;
    }
```    
上面的```dfs(count, presum, i)```表示我们已经选择了i-1个groups（它们的前缀和是presum，哪些被选择了记录在count里），我们从剩下的groups挑选一个安排在第i个。选哪个好呢？我们不知道，必须每种可能都尝试一次，结合相应的```dfs(..., i+1)```来判断。这里需要注意的是，如果此时的presum恰好被batch整除，那么说明无论第i个元素取谁，我们都可以得到1分。所以返回的答案就是下轮递归 里的最大值，再加本轮的1。

以上的解法自然会TLE，原因是什么呢？显然是没有记忆化。我们可以发现，dfs函数中，其实只要确定了当前的count（即未被安排的groups），其他的参数presum本质上就是确定了的。所以记忆化的key其实就是count。但是count是一个数组，如何将转化为一个方便的key呢？和状态压缩相同的原因。因为count[i]最多30个，用五个bit就能表示（0~32）。batch最多是9，所以总共45位的二进制数就可以表述count数组。这就要求这个key是long long类型。

我们再分析一下这样的记忆化搜索为什么不会超时？因为每次dfs我们都在查询/创建一个key，我们就思考一下我们最多会有多少个key？看上去似乎count的每个bin最多会有30个，总共有9个bin，因此有30^9个。但实际上并没有这么多，因为这30个元素是分布在9个bin里面的，这是一个约束。只有当每个bin的频次均匀分布时，才对应着最复杂的情况，即```(30/9)^9=50805```种。试想一下，如果30个元素属于同一个bin里面，那么其实只有30种key。综上所述，dfs是复杂度可行的算法。
