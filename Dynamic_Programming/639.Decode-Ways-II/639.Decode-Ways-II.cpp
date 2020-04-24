class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        s = "#"+s;
        vector<long>dp(n+1,0);
        long M = 1e9+7;

        dp[0] = 1;
        if (s[1] == '*') dp[1] = 9;
        else if (s[1] == '0') dp[1] = 0;
        else dp[1] = 1;

        for (int i=2; i<=n; i++)
        {
            if (isdigit(s[i]))
            {
                dp[i] += s[i]=='0' ? 0:dp[i-1];
                if (isdigit(s[i-1]))
                {
                    int num = (s[i-1]-'0')*10+(s[i]-'0');
                    if (num>=10 && num<=26)
                        dp[i]+=dp[i-2];
                }
                else
                {
                    if (s[i]<='6') dp[i] += dp[i-2]*2;
                    else dp[i] += dp[i-2];
                }                
            }
            else
            {
                dp[i] += dp[i-1]*9;
                if (s[i-1]=='1') dp[i]+=dp[i-2]*9;
                else if (s[i-1]=='2') dp[i]+=dp[i-2]*6;
                else if (s[i-1]=='*') dp[i]+=dp[i-2]*15;
            }
            dp[i]%=M;
        }
        return dp[n];
    }
};
