class Solution {
public:
    int maxGroupNumber(vector<int>& tiles) 
    {
        map<int,int>count;
        for (auto x: tiles)
            count[x]++;

        vector<vector<int>>dp(5,vector<int>(5));
        int last = -1;

        for (auto [val, freq]: count)
        {
            if (last!=val-1)
            {
                int maxDp = 0;
                for (int i=0; i<=4; i++)
                    for (int j=0; j<=4; j++)
                    {
                        maxDp = max(maxDp, dp[i][j]);
                        dp[i][j] = -1;                        
                    }                        
                dp[0][0] = maxDp;
            }

            vector<vector<int>>dp2(5,vector<int>(5, -1));
            for (int i=0; i<=4; i++)
                for (int j=0; j<=4; j++)
                {
                    if (dp[i][j]==-1) continue;

                    for (int a = 0; a <= min(freq, min(i, j)); a++) // # of (x-2, x-1, x)
                    {                        
                        int j_max = j - a;
                        int k_max = min(4, freq - a);

                        for (int jj=0; jj<=j_max; jj++)
                            for (int kk=0; kk<=k_max; kk++)
                            {
                                dp2[jj][kk] = max(dp2[jj][kk], dp[i][j] + a + (j - a - jj)/3 + (freq - a - kk)/3 + (i - a)/3); 
                            }
                    }                    
                }
            dp = move(dp2);
            last = val;
        }

        int ret = 0;
        for (int i=0; i<=4; i++)
            for (int j=0; j<=4; j++)
                ret = max(ret, dp[i][j]);
        return ret;
    }
};
