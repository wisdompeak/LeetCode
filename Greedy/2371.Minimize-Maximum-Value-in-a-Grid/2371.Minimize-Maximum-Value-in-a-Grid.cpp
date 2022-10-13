class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>arr;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
            {
                arr.push_back({grid[i][j], i, j});
            }
        
        sort(arr.begin(), arr.end());
        vector<int>rows(m,0);
        vector<int>cols(n,0);
        
        for (int i=0; i<arr.size(); i++)
        {
            int x = arr[i][1], y = arr[i][2];
            
            int t = 1;
            t = max(t, rows[x]+1);
            t = max(t, cols[y]+1);
                        
            grid[x][y] = t;
            rows[x] = t;
            cols[y] = t;
        }
        
        return grid;
    }
};
