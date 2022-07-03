using AI3 = array<int,3>;
using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) 
    {
        vector<AI3>array;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                array.push_back({grid[i][j], i, j});
        
        sort(array.begin(), array.end());
        
        vector<vector<LL>>dp(m, vector<LL>(n, 0));
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        LL ret = 0;
        for (auto& [v, i, j]: array)
        {
            LL sum = 0;
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (grid[x][y] >= grid[i][j]) continue;
                sum = (sum + dp[x][y]) % M;
            }
            sum = (sum + 1) % M;
            dp[i][j] = sum;
            ret = (ret + sum) % M;
        }
        
        return ret;
        
    }
};
