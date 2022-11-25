class Solution {
    long dp[2005];
    long M = 1e9+7;
public:
    int distinctSubseqII(string s) 
    {
        int n = s.size();
        s = "#"+s;
        vector<int>last(26,0);
        dp[0] = 1;

        for (int i=1; i<=n; i++)
        {
            int j = last[s[i]-'a'];
            dp[i] = dp[i-1] *2 %M - (j>=1 ? dp[j-1] : 0);
            dp[i] = (dp[i]+M) % M;
            last[s[i]-'a'] = i;
        }

        return (dp[n] -1 +M) % M;        
    }
};
