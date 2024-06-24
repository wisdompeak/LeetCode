class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) 
    {
        int ret = INT_MAX;

        int m = grid.size(), n = grid[0].size();

        /*************************/
        1.        2.      3.
                    
        ┌－┐      ┌┐┌┐    ┌－┐
        └－┘      └┘└┘    └－┘
        ┌－┐      ┌－┐    ┌┐┌┐
        └－┘      └－┘    └┘└┘
        ┌－┐
        └－┘
        
        4.       5.      6.
        ┌┐┌┐┌┐   ┌ ┐┌┐    ┌┐┌ ┐
        └┘└┘└┘   │ │└┘    └┘│ │
                 │ │┌┐    ┌┐│ │
                 └ ┘└┘    └┘└ ┘
       /*************************/

        for (int i=1; i<m; i++)
            for (int j=i+1; j<m; j++)
            {
                int area1 = process(grid, 0,0,i-1,n-1);
                int area2 = process(grid, i,0,j-1,n-1);
                int area3 = process(grid, j,0,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                int area1 = process(grid, 0,0,i-1,j-1);
                int area2 = process(grid, 0,j,i-1,n-1);
                int area3 = process(grid, i,0,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                int area1 = process(grid, 0,0,i-1,n-1);
                int area2 = process(grid, i,0,m-1,j-1);
                int area3 = process(grid, i,j,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }

        for (int i=1; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                int area1 = process(grid, 0,0,m-1,i-1);
                int area2 = process(grid, 0,i,m-1,j-1);
                int area3 = process(grid, 0,j,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                int area1 = process(grid, 0,0,m-1,j-1);
                int area2 = process(grid, 0,j,i-1,n-1);
                int area3 = process(grid, i,j,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
            {
                int area1 = process(grid, 0,0,i-1,j-1);
                int area2 = process(grid, i,0,m-1,j-1);
                int area3 = process(grid, 0,j,m-1,n-1);
                ret = min(ret, area1+area2+area3);
            }
        
        return ret;
    }   

    int process(vector<vector<int>>& grid, int a, int b, int c, int d) 
    {        
        if (a>c || b>d) return INT_MAX/3;
        int left = INT_MAX, top = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        for (int i=a; i<=c; i++)
            for (int j=b; j<=d; j++)
            {
                if (grid[i][j]==0) continue;
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        if (bottom>=top && right>=left)
            return (bottom-top+1)*(right-left+1);
        else
            return INT_MAX/3;
    }
};
