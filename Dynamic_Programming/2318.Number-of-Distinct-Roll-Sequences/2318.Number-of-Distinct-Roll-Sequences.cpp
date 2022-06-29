using LL = long long;
LL M = 1e9+7;
class Solution {
    LL dp[10001][7][7];
public:
    int distinctSequences(int n) 
    {
        if (n==1) return 6;

        LL count = 0;        
        for (int a=1; a<=6; a++)
            for (int b=1; b<=6; b++)
            {
                if (a!=b && gcd(a,b)==1)
                {
                    dp[2][a][b] = 1;                
                    count++;
                }                    
            }
        if (n==2) return count;
        
        LL ret = 0;
        for (int i=3; i<=n; i++)
            for (int a=1; a<=6; a++)
                for (int b=1; b<=6; b++)
                {
                    if (a==b) continue;
                    if (gcd(a,b)>1) continue;

                    for (int x=1; x<=6; x++)
                    {
                        if (x!=b)
                        {
                            dp[i][a][b] += dp[i-1][x][a];
                            dp[i][a][b] %= M;                            
                        }                        
                    }                   

                    if (i==n)
                        ret = (ret + dp[i][a][b]) %M;
                }

        return ret;
    }
};
