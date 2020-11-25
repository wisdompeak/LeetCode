class Solution {    
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());

        int n = digits.size();
        digits.insert(digits.begin(), 0);
        
        string dp[n+1][3];
        dp[0][0] = "", dp[0][1] = "#", dp[0][2] = "#";
        
        for (int i=1; i<=n; i++)        
            for (int j=0; j<3; j++)
            {                
                if (dp[i-1][j]=="#" && dp[i-1][(j-digits[i]%3+3)%3]=="#")
                {
                    dp[i][j] = "#";
                }
                else if (dp[i-1][j]=="#")
                {
                    dp[i][j] = dp[i-1][(j-digits[i]%3+3)%3] + to_string(digits[i]);
                }
                else if (dp[i-1][(j-digits[i]%3+3)%3]=="#")
                {
                    dp[i][j] = dp[i-1][j];
                }
                else if (dp[i-1][j].size() >= dp[i-1][(j-digits[i]%3+3)%3].size()+1)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][(j-digits[i]%3+3)%3] + to_string(digits[i]);
                }
            }

        string ret = dp[n][0];
        if (ret[0]=='0')
            return "0";
        else
            return ret;
    }

};

