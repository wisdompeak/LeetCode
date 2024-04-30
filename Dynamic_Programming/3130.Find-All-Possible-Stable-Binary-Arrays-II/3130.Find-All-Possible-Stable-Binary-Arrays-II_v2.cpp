using LL = long long;
class Solution {
    LL dp0[205][205];
    LL dp1[205][205];
    LL presum0[205][205];
    LL presum1[205][205];
    LL M = 1e9+7;
public:
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        dp0[0][0]=1;
        dp1[0][0]=1;
        presum0[0][0] = 1;
        presum1[0][0] = 1;
        
        for (int i=0; i<=zero; i++)
            for (int j=0; j<=one; j++)
            {
                if (i==0 && j==0) continue;

                // 1<=k<=min(i,limit)
                dp0[i][j] = (i-1<0?0:presum1[j][i-1]) - (i-min(i,limit)-1<0?0:presum1[j][i-min(i,limit)-1]);


                // 1<=k<=min(j,limit)                                
                dp1[i][j] = (j-1<0?0:presum0[i][j-1]) - (j-min(j,limit)-1<0?0:presum0[i][j-min(j,limit)-1]);

                dp0[i][j] = (dp0[i][j] + M) %M;
                dp1[i][j] = (dp1[i][j] + M) %M;

                presum0[i][j] = (j<1?0:presum0[i][j-1]) + dp0[i][j];
                presum1[j][i] = (i<1?0:presum1[j][i-1]) + dp1[i][j];

                presum0[i][j] %= M;
                presum1[j][i] %= M;
            }
        
        return (dp0[zero][one]+dp1[zero][one]) % M;
    }
};
