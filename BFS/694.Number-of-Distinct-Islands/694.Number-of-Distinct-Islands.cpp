class Solution {
    unordered_set<string>Set;
public:
    int numDistinctIslands(vector<vector<int>>& grid) 
    {
        int M=grid.size();
        int N=grid[0].size();
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
                
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0,},{0,-1}};        
        
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (grid[i][j]==0) continue;
             if (visited[i][j]==1) continue;
             
             string path="*";
             queue<pair<int,int>>q;
             q.push({i,j});
             visited[i][j]=1;
             
             while (!q.empty())
             {
                 int m=q.front().first;
                 int n=q.front().second;
                 q.pop();
                 
                 for (int k=0; k<4; k++)
                 {
                    int x=m+dir[k].first;
                    int y=n+dir[k].second;
                 
                    if (x<0||x>=M||y<0||y>=N || grid[x][y]==0 || visited[x][y]==1) 
                        continue;                                         
                    
                    visited[x][y]=1;
                    path+=to_string(k);
                    q.push({x,y});
                 }
                 path+='*';
             }
             
             Set.insert(path);             
         }
        
        return Set.size();        
    }    
};
