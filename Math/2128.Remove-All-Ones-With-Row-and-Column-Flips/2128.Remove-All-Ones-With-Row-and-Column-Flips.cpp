class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i=1; i<m; i++)
        {            
            if (checkSame(grid, 0, i)) continue;
            if (checkFlip(grid, 0, i)) continue;
            return false;
        }
        return true;        
    }
    
    bool checkSame(vector<vector<int>>& grid, int a, int b)
    {
        int n = grid[0].size();
        for (int j=0; j<n; j++)
            if (grid[a][j]!=grid[b][j])
                return false;
        return true;
    }
    
    bool checkFlip(vector<vector<int>>& grid, int a, int b)
    {
        int n = grid[0].size();
        for (int j=0; j<n; j++)
            if (grid[a][j]!=1-grid[b][j])
                return false;
        return true;
    }
};
