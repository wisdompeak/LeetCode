using LL = long long;
using PLL = pair<LL,LL>;
class Solution {
    vector<int>next[100005];
    LL sum1[100005];
    LL sum2[100005];
    LL ret = 0;
    int n;
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) 
    {
        this->n = n;
    
        // if (n==1) return 0;
        
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);            
        }
        
        dfs(0, -1, price);
        
        dfs2(0, -1, price);
        
        return ret;
    }
    
    void dfs(int cur, int prev, vector<int>& price)
    {
        if ((next[cur].size()==1 && next[cur][0] == prev) || next[cur].size() == 0)
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
    
    void dfs2(int cur, int prev, vector<int>& price)
    {
        if (next[cur].size()==1 && next[cur][0] == prev)
            return;
        
        LL ans = max(sum1[cur], sum2[cur]-price[cur]);
       
        vector<PLL>arr1;
        vector<PLL>arr2;
        
        for (int nxt: next[cur])
        {
            if (nxt==prev) continue;
            arr1.push_back({sum1[nxt], nxt});
            arr2.push_back({sum2[nxt], nxt});                
        }
        sort(arr1.rbegin(), arr1.rend());
        sort(arr2.rbegin(), arr2.rend());
        
        if (arr1.size()>=2)
        {
            if (arr1[0].second!=arr2[0].second)
                ans = max(ans, arr1[0].first+arr2[0].first+price[cur]);
            else
                ans = max(ans, max(arr1[0].first+arr2[1].first+price[cur], arr1[1].first+arr2[0].first+price[cur]));                
        }
                
        ret = max(ret, ans);
        
        for (int nxt: next[cur])
        {
            if (nxt==prev) continue;
            dfs2(nxt, cur, price);
        }        
    }
};
