using LL = long long;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) 
    {
        map<LL,LL>p;
        for (int x: power)
            p[x]++;
        
        vector<pair<LL,LL>>arr(p.begin(), p.end());
        
        vector<LL>dp(arr.size());
        
        LL ret = 0;        
        for (int i=0; i<arr.size(); i++)
        {
            auto [x, count] = arr[i];
            
            LL ans = x*count;
            
            if (i>=1) ans = max(ans, dp[i-1]);
            
            if (i>=1 && arr[i-1].first<x-2)
                ans = max(ans, dp[i-1] + x*count);
            else if (i>=2 && arr[i-2].first<x-2)
                ans = max(ans, dp[i-2] + x*count);
            else if (i>=3 && arr[i-3].first<x-2)
                ans = max(ans, dp[i-3] + x*count);
            
            dp[i] = ans;

            ret = max(ret, ans);
        }
        
        return ret;        
    }
};
