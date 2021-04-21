class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int N = s.size();
        s = "#"+s;
        vector<bool>dp(N+1,0);
        
        dp[0] = true;
        
        for (int i=1; i<=N; i++)
        {
            // updaet dp[i]
            for (auto x: wordDict)
            {
                if (i>=x.size() && s.substr(i-x.size()+1,x.size())==x && dp[i-x.size()])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[N];
    }
};
