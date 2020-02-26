class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        int m = arr.size();
        int n = arr[0].size();
        
        auto dp = vector<vector<int>>(m,vector<int>(n));
        for (int j=0; j<n; j++)
            dp[0][j] = arr[0][j];
        
        for (int i=1; i<m; i++)
        {
            vector<pair<int,int>>temp;
            for (int k=0; k<n; k++)
                temp.push_back({dp[i-1][k], k});
            sort(temp.begin(), temp.end());
            
            for (int j=0; j<n; j++)
            {
                if (j!=temp[0].second)
                    dp[i][j] = temp[0].first + arr[i][j];
                else
                    dp[i][j] = temp[1].first + arr[i][j];
            }
        }
        
        int ret = INT_MAX;
        for (int j=0; j<n; j++)
            ret = min(ret, dp[m-1][j]);
        return ret;
            
    }
};
