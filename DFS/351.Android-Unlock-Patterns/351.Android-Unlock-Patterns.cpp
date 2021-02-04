class Solution {
    int count = 0;
    int m,n;
public:
    int numberOfPatterns(int m, int n) 
    {
        this->m = m;
        this->n = n;        
        auto visited = vector<vector<int>>(3, vector<int>(3,0));
        
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
            {
                visited[i][j] = 1;
                dfs(i,j,1,visited);
                visited[i][j] = 0;
            }
        return count;        
    }
    
    void dfs(int x, int y, int r, vector<vector<int>>&visited)
    {        
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1},{-1,2},{1,2},{-2,1},{2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}});
        if (r>=m && r<=n)
            count++;
        if (r>n) return;
        
        for (int k=0; k< dir.size(); k++)
        {
            int i = x+dir[k].first;
            int j = y+dir[k].second;
            if (i<0||i>=3||j<0||j>=3)
                continue;        
            if (visited[i][j] == 0)
            {
                visited[i][j] = 1;
                dfs(i,j,r+1,visited);
                visited[i][j] = 0;
            }                
            else
            {
                i = i+dir[k].first;
                j = j+dir[k].second;
                if (i<0||i>=3||j<0||j>=3)
                    continue;     
                if (visited[i][j]==1) continue;
                visited[i][j] = 1;
                dfs(i,j,r+1,visited);
                visited[i][j] = 0;
            }            
        }        
    }
};
