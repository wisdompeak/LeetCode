class Solution {
public:
    int regionsBySlashes(vector<string>& grid) 
    {
        int N = grid.size();
        auto Grid = vector<vector<int>>(N*3,vector<int>(N*3,0));
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                if (grid[i][j]=='/')
                {
                    Grid[i*3+0][j*3+2] = 1;
                    Grid[i*3+1][j*3+1] = 1;
                    Grid[i*3+2][j*3+0] = 1;
                }
                else if (grid[i][j]=='\\')
                {
                    Grid[i*3+0][j*3+0] = 1;
                    Grid[i*3+1][j*3+1] = 1;
                    Grid[i*3+2][j*3+2] = 1;
                }
            }

        int count = 0;
        for (int i=0; i<N*3; i++)
            for (int j=0; j<N*3; j++)
            {
                if (Grid[i][j]==0)
                {
                    DFS(Grid,i,j);
                    count++;
                }
            }
        return count;
    }
    
    void DFS(vector<vector<int>>&Grid, int x, int y)
    {
        int M = Grid.size();
        if (x<0||x>=M||y<0||y>=M) return;
        if (Grid[x][y]!=0) return;
        Grid[x][y]=2;
        
        vector<pair<int,int>>dir({{0,1},{0,-1},{1,0},{-1,0}});
        for (int k=0; k<4; k++)
        {
            int i = x+dir[k].first;
            int j = y+dir[k].second;
            DFS(Grid,i,j);
        }
    }
};
