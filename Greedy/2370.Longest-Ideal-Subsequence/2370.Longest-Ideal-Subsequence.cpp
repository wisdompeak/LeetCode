class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        int n = s.size();
        s = "#"+s;
        vector<int>prev(26, 0);
        vector<int>dp(n+1,1);
        dp[0] = 0;
                
        int ret = 0;
        for (int i=1; i<=n; i++)
        {
            for (int j=max(0,s[i]-'a'-k); j<=min(25, s[i]-'a'+k); j++)
            {
                int p = prev[j];
                dp[i] = max(dp[i], dp[p]+1);
            }       
            prev[s[i]-'a'] = i;
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};
