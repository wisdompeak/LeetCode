using LL = long long;
LL M = 1e9+7;
class Solution {
    int n;
    LL dp[305][305];
public:
    LL getXPower(int a, int x)
    {
        LL ret = 1;
        for (int i=0; i<x; i++)
        {
            ret *= a;
            if (ret > n)
                return INT_MAX;
        }
        return ret;
    }
    
    int numberOfWays(int n, int x) 
    {
        this->n = n;
                        
        dp[0][0] = 1;
        
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                LL cur = getXPower(j,x);
                if (cur>i) break;
                
                for (int jj=0; jj<j; jj++)
                {
                    dp[i][j] += dp[i-cur][jj];
                    dp[i][j] %= M;
                }
            }            
        }
        
        LL ret = 0;
        for (int j=1; j<=n; j++)
        {
            LL cur = getXPower(j,x);
            if (cur>n) break;
            ret += dp[n][j];
            ret %= M;
        }
        return ret;
    }
};
