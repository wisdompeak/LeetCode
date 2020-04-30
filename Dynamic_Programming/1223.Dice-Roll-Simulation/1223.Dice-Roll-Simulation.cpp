class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) 
    {
        int M = 1e9+7;        
        auto dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(7,vector<int>(16,0)));
        rollMax.insert(rollMax.begin(),0);

        for (int j=1; j<=6; j++)
            dp[1][j][1] = 1;

        for (int i=2; i<=n; i++)
            for (int j=1; j<=6; j++)
                for (int k=1; k<=rollMax[j]; k++)
                {
                    if (k==1)
                    {
                        for (int jj=1; jj<=6; jj++)
                        {
                            if (jj==j) continue;
                            for (int kk=1; kk<=rollMax[jj]; kk++)
                                dp[i][j][k] = (dp[i][j][k] + dp[i-1][jj][kk])%M;
                        }
                    }
                    else
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1])%M;
                    }
                }
    
        int sum = 0;
        for (int j=1; j<=6; j++)
            for (int k=1; k<=rollMax[j]; k++)
                sum = (sum + dp[n][j][k])%M;

        return sum;

    }
};
