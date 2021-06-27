typedef long long ll;
class Solution {
    ll dp[100005];
    ll num[100005];
    vector<int> next[100005];    
    ll f[100005];
    ll M = 1e9+7;
    
public:
    int waysToBuildRooms(vector<int>& prevRoom) 
    {
        int n = prevRoom.size();        
        for (int i=1; i<prevRoom.size(); i++)                            
            next[prevRoom[i]].push_back(i);       
         
        f[0] = 1;
        for (int i=1; i<=n; i++)
            f[i] = f[i-1]*i %M;
        
        dfs(0);
        return dp[0];
    }
    
    void dfs(int node)
    {
        if (next[node].size()==0)
        {
            dp[node] = 1;
            num[node] = 1;
            return;
        }
        
        for (auto x: next[node])
            dfs(x);
        
        ll sum = 0;
        for (auto x: next[node])
            sum += num[x];
        
        num[node] = sum + 1;
        
        ll ret = f[sum];
                
        for (auto x: next[node])        
            ret = ret * inv(f[num[x]]) %M;                               
        
        for (auto x: next[node])        
            ret = ret * dp[x] % M;        
        
        dp[node] = ret;
    }
    
    
    ll inv(ll x) 
    {     
        ll s = 1;
        for (; x > 1; x = M%x)
          s = s*(M-M/x)%M;        
        return s;
    }
};
