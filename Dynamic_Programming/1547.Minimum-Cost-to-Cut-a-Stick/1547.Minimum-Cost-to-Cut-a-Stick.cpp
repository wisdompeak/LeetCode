class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        int m = cuts.size()+1;
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        
        auto dp = vector<vector<int>>(m+1, vector<int>(m+1, INT_MAX/2));
        for (int i=0; i<m; i++)
            dp[i][i+1] = 0;
        
        for (int len=2; len<=m; len++)
            for (int i=0; i+len<=m; i++)
            {
                int j = i+len;
                for (int k=i+1; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);                
            }
        return dp[0][m];                
    }
};
