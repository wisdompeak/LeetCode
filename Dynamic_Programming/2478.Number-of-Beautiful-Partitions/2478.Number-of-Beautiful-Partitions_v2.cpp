using LL = long long;
class Solution {
    LL dp[1005][1005];
    LL M = 1e9+7;
public:
    int beautifulPartitions(string s, int K, int minLength) 
    {
        int n = s.size();
        s = "#"+s;
        
        dp[0][0] = 1;
        for (int j=1; j<=K; j++)
        {
            LL sum = 0;
            for (int i=1; i<=n; i++)            
            {    
                if (i-minLength>=0 && !isprime(s[i-minLength]) && isprime(s[i-minLength+1]))
                {
                    sum += dp[i-minLength][j-1];
                    sum %= M;
                }
                if (!isprime(s[i])) {
                    dp[i][j] = sum;                    
                }                
            }
        }
        return dp[n][K];
    }
                    
    bool isprime(char ch)
    {
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }     
};
