using LL = long long;
class Solution {
    LL dp0[205][205];
    LL dp1[205][205];
    LL M = 1e9+7;
public:
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        dp0[0][0]=1;
        dp1[0][0]=1;
        
        for (int i=0; i<=zero; i++)
            for (int j=0; j<=one; j++)
            {
                if (i==0 && j==0) continue;

                for (int k=1; k<=limit; k++)
                {
                    if (i-k>=0) dp0[i][j] += dp1[i-k][j];
                    if (j-k>=0) dp1[i][j] += dp0[i][j-k];
                    dp0[i][j] %= M;
                    dp1[i][j] %= M;
                }
            }
        
        return (dp0[zero][one]+dp1[zero][one]) % M;
    }
};
