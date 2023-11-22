using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[100005][2][3][2];
public:
    int stringCount(int n) 
    {
        dp[0][0][0][0] = 1;
        for (int i=1; i<=n; i++)
            for (int a=0; a<2; a++)
                for (int b=0; b<3; b++)
                    for (int c=0; c<2; c++)
                    {
                        for (int k=0; k<26; k++)
                        {
                            if (k==('l'-'a') && a==1)
                                dp[i][1][b][c] += dp[i-1][0][b][c];
                            else if (k==('e'-'a') && b==1)
                                dp[i][a][1][c] += dp[i-1][a][0][c];
                            else if (k==('e'-'a') && b==2)
                                dp[i][a][2][c] += dp[i-1][a][1][c];
                            else if (k==('t'-'a') && c==1)
                                dp[i][a][b][1] += dp[i-1][a][b][0];
                            else
                            {
                                dp[i][a][b][c] += dp[i-1][a][b][c];
                                dp[i][a][b][c] %= M;
                            }                                
                        }
                    }

        return dp[n][1][2][1];

    }
};
