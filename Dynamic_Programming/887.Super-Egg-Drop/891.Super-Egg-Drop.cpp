class Solution {
public:
    int superEggDrop(int K, int N) 
    {
        auto dp = vector<vector<int>>(K+1,vector<int>(N+1,0));
        
        int m = 0;
        
        while (dp[K][m]<N)
        {
            m++;
            for (int k=1; k<=K; k++)
                dp[k][m] = dp[k-1][m-1]+1+dp[k][m-1];
        }
        return m;
    }
};
