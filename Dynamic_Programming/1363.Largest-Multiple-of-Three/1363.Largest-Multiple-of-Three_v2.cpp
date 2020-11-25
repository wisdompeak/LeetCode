class Solution {    
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());

        int n = digits.size();
        digits.insert(digits.begin(), 0);
        
        int dp[n+1][3];
        int prev[n+1][3];
        int pick[n+1][3];
        dp[0][0] = 0, dp[0][1] = INT_MIN, dp[0][2] = INT_MIN;
        
        for (int i=1; i<=n; i++)        
            for (int j=0; j<3; j++)
            {                
                if (dp[i-1][j] >= dp[i-1][(j-digits[i]%3+3)%3]+1)
                {
                    dp[i][j] = dp[i-1][j];
                    prev[i][j] = j;
                    pick[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][(j-digits[i]%3+3)%3]+1;
                    prev[i][j] = (j-digits[i]%3+3)%3;
                    pick[i][j] = 1;
                }
            }

        int j = 0;
        string ret;
        for (int i=n; i>=1; i--)
        {
            if (pick[i][j])
                ret += '0'+digits[i];
            j = prev[i][j];
        }

        reverse(ret.begin(), ret.end());
        if (ret[0]=='0')
            return "0";
        else
            return ret;
    }
};
