using LL = long long;
LL M = 1e9+7;
class Solution {
    vector<pair<int,int>>arr;  
    int count0 = 0;
public:
    int countSubMultisets(vector<int>& nums, int l, int r)     
    {        
        unordered_map<int,int>Map;
        for (int x: nums)
        {
            if (x==0) count0++;
            else Map[x]++;
        }
                                    
        for (auto& p:Map)
            arr.push_back(p);
            
        arr.insert(arr.begin(), {0,0});
        
        return (helper(r) - helper(l-1) + M) % M;        
    }
    
    int helper(int limit)
    {
        if (limit<0) return 0;
        
        int n = arr.size() - 1;
        
        vector<vector<LL>>dp(n+1, vector<LL>(limit+1, 0));
        
        dp[0][0] = 1;
                
        for (int i=1; i<=n; i++)
        {
            auto [v, c] = arr[i];            
            for (int j=0; j<=limit; j++)
            {                
                dp[i][j] = (j<v?0:dp[i][j-v]) + dp[i-1][j] - (j<v*(c+1)?0:dp[i-1][j-v*(c+1)]);
                dp[i][j] = (dp[i][j]+M) % M;
            }
        }
        
        LL ret = 0;
        for (int j=0; j<=limit; j++)
            ret = (ret+dp[n][j]) % M;
                
        return max(1LL, ret) * (count0+1) % M;
    }
};
