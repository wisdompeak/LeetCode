### 1815.Maximum-Number-of-Groups-Getting-Fresh-Donuts

我们从数据的规模上来看，应该猜测这是一个NP问题，解法应该是基于搜索。因为groups的总数最多只有30，暴力搜索也许可行？于是我们可以写出第一个版本：
```cpp
    int dfs(vector<int>&count, int presum, int prescore, int i)
    {
        if (i==n) 
            return prescore;
        
        if (presum % b == 0)
            prescore++;

        int ret = 0;
        for (int j=0; j<b; j++)
        {
            if (count[j]==0) continue;
            count[j]--;
            ret = max(ret, dfs(count, (presum+j) % b, prescore, i+1));
            count[j]++;
        }
        return ret;
    }
```    
上面的```dfs(int presum, int prescore, int i)```表示我们已经选择了i-1个groups（它们的前缀和是presum、已有的得分是prescore），我们从剩下的groups挑选一个安排在第i个。选哪个好呢？我们不知道，必须每种可能都尝试一次，结合相应的```dfs(..., i+1)```来判断。这里需要注意的是，如果此时的presum恰好被batch整除，那么说明无论第i个元素取谁，我们都可以得到1分，所以下次递归的时候perscore可以增加1。

以上的解法自然会TLE，原因是什么呢？显然是没有记忆化。我们可以发现，dfs函数中，其实只要确定了当前的count（即未被安排的groups），其他的参数presum和prescore都是相应地可以确定的。所以记忆化的key其实就是count。但是count是一个数组，如何将转化为一个方便的key呢？
