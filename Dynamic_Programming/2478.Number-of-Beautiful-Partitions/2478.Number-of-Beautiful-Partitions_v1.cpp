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
        for (int i=1; i<=n; i++)
            for (int j=1; j<=K; j++)
            {
                if (isprime(s[i])) {
                    continue;
                }
                for (int k=j; (k+minLength-1)<=i; k++)
                {
                    if (isprime(s[k]))
                        dp[i][j] = (dp[i][j] + dp[k-1][j-1]) % M;
                }
            }
        return dp[n][K];
    }
                    
    bool isprime(char ch)
    {
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }

                
};
