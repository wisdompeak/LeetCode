class Solution {
public:
    string longestPrefix(string s) 
    {
        int n = s.size();
        vector<int>dp(n);
        dp[0] = 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && s[j]!=s[i])
            {
                j = dp[j-1];
            }          
            dp[i] = j + (s[j]==s[i]);
        }

        int len = dp[n-1];
        return s.substr(0, len);
    }
};
