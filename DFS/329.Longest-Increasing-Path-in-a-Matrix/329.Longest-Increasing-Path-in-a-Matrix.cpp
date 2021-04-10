class Solution {
    int m,n;
    int len[200][200];
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        m = matrix.size();
        n = matrix[0].size();
        
        int ret = 0;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                ret = max(ret, dfs(matrix,i,j));                    
            }
        
        return ret;
    }
    
    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (len[i][j]!=0) return len[i][j];
        vector<pair<int,int>>dir({{0,1},{0,-1},{1,0},{-1,0}});
        int ret = 0;
        for (int k=0; k<4; k++)
        {
            int x = i+dir[k].first;
            int y = j+dir[k].second;
            if (x<0||x>=m||y<0||y>=n) continue;
            if (matrix[x][y]<=matrix[i][j]) continue;
            ret = max(ret, dfs(matrix, x,y));
        }
        len[i][j] = 1+ret;
        return 1+ret;
    }
};
