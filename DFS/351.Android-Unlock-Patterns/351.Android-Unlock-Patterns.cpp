class Solution {
    int count = 0;
    int m,n;
    int visited[3][3];
    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1},{-1,2},{1,2},{-2,1},{2,1},{-1,-2},{1,-2},{-2,-1},{2,-1}};
public:
    int numberOfPatterns(int m, int n) 
    {
        this->m = m;
        this->n = n;        
                
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
            {
                visited[i][j] = 1;
                dfs(i,j,1);
                visited[i][j] = 0;
            }
        return count;        
    }
    
    void dfs(int x, int y, int r)
    {                
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
                dfs(i,j,r+1);
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
                dfs(i,j,r+1);
                visited[i][j] = 0;
            }            
        }        
    }
};
