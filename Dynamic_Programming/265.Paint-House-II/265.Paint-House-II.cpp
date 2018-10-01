class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        int N = costs.size();
        if (N==0) return 0;
        int K = costs[0].size();
                
        auto dp = vector<vector<int>>(N,vector<int>(K,0));
        int minColor1 = -1;
        int minColor2 = -1;
        
        for (int i=0; i<N; i++)
        {
            int min1 = INT_MAX, min2 = INT_MAX;
            int newMinColor1, newMinColor2;
            
            for (int j=0; j<K; j++)
            {
                if (j==minColor1)                
                    dp[i][j] = (i==0)? costs[i][j] : dp[i-1][minColor2]+costs[i][j];
                else
                    dp[i][j] = (i==0)? costs[i][j] : dp[i-1][minColor1]+costs[i][j];
                
                if (dp[i][j]<min1)
                {
                    min2 = min1; newMinColor2 = newMinColor1;
                    min1 = dp[i][j]; newMinColor1 = j;                    
                }
                else if (dp[i][j]<min2)
                {
                    min2 = dp[i][j]; newMinColor2 = j;
                }
            }
            minColor1 = newMinColor1;
            minColor2 = newMinColor2;
        }
        return dp[N-1][minColor1];        
    }
};
