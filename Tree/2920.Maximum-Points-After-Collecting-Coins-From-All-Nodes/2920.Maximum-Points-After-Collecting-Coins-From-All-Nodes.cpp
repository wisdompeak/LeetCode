class Solution {
    int memo[100005][14];
    vector<int>next[100005];
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) 
    {
        int n = edges.size()+1;
        for (int i=0; i<n; i++)
            for (int j=0; j<14; j++)
                memo[i][j] = INT_MIN/2;
        
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        return dfs(0, -1, 0, coins, k);
    }
    
    int helper(int x, int r)
    {
        for (int i=0; i<r; i++)
            x = x/2;
        return x;
    }
    
    int dfs(int cur, int parent, int reduced, vector<int>& coins, int k)
    {        
        if (reduced >= 13) reduced = 13;
        
        if (memo[cur][reduced]!=INT_MIN/2)
            return memo[cur][reduced];
        
        int sum1 = helper(coins[cur], reduced) - k;
        for (int nxt: next[cur])
        {
            if (nxt == parent) continue;
            sum1 += dfs(nxt, cur, reduced, coins, k);
        }
        
        int sum2 = helper(coins[cur], reduced)/2;
        for (int nxt: next[cur])
        {
            if (nxt == parent) continue;
            sum2 += dfs(nxt, cur, reduced+1, coins, k);
        }
        
        memo[cur][reduced] = max(sum1, sum2);            
        return memo[cur][reduced];
    }
};
