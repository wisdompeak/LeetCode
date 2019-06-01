class Solution {
public:
    int distinctSubseqII(string S) 
    {
        int N = S.size();
        S= "#"+S;
        vector<long>dp(N+1,0);
        unordered_map<char,int>Map;
        long M = 1e9+7;
        dp[0] = 1;
        
        for (int i=1; i<=N; i++)
        {
            dp[i] = dp[i-1]*2%M;
            if (Map.find(S[i])!=Map.end())
                dp[i] = (dp[i]+M-dp[Map[S[i]]-1])%M;
            Map[S[i]] = i;                        
        }
        
        return dp[N]-1;
        
    }
};
