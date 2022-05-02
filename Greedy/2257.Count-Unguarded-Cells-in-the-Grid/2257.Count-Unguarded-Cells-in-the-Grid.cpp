class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>>matrix(m, vector<int>(n));        
        for (auto guard: guards)
            matrix[guard[0]][guard[1]] = 2;
        for (auto wall: walls)
            matrix[wall[0]][wall[1]] = 2;
        
        vector<pair<int,int>>dir({{1,0},{-1,0},{0,1},{0,-1}});
        for (auto guard: guards)                   
            for (auto [dx, dy]: dir)
            {                
                int i = guard[0], j = guard[1];
                while (1)
                {
                    i+=dx;
                    j+=dy;
                    if (i<0||i>=m || j<0||j>=n) break;
                    if (matrix[i][j]==2) break;
                    matrix[i][j] = 1;
                }
            }
        
        int ret = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (matrix[i][j]==0)
                    ret++;
        
        return ret;
    }
};
