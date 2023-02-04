class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--)
            {
                if (i==m-1 && j==n-1) continue;
                if ((i+1>=m || grid[i+1][j]==0) && (j+1>=n || grid[i][j+1]==0))
                    grid[i][j] = 0;
            }
        if (grid[0][0]==0) return true;            
        
        int x1=0, y1=0, x2=0, y2=0;
        for (int k=0; k<m+n-3; k++)
        {
            if (y1+1<n && grid[x1][y1+1]==1)
                y1++;
            else
                x1++;
            
            if (x2+1<m && grid[x2+1][y2]==1)
                x2++;
            else
                y2++;
            
            if (x1==x2 && y1==y2)
                return true;
        }
        
        return false;
    }
};
