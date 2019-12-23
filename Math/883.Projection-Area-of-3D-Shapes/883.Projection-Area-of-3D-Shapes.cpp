class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        int ret=0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                row[i] = max(row[i],grid[i][j]);
                col[j] = max(col[j],grid[i][j]);
                ret+=(grid[i][j]>0);
            }
        
        for (int i=0; i<m; i++)
            ret+=row[i];
        for (int j=0; j<n; j++)
            ret+=col[j];

        return ret;
    }
};
