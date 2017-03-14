class Solution {
private:
    int M;
    int N;
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        M=grid.size();
        if (M==0) return 0;
        N=grid[0].size();
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        auto dir=vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}};
        
        int count=0;
        queue<pair<int,int>>q;
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (grid[i][j]=='0' || visited[i][j]==1) continue;
             
             visited[i][j]=1;
             q.push({i,j});
             count++;
             
             while (!q.empty())
             {
                 
                 for (int k=0; k<4; k++)
                 {
                     int m=q.front().first+dir[k].first;
                     int n=q.front().second+dir[k].second;
                     if (m>=0 && m<M && n>=0 && n<N && visited[m][n]==0 && grid[m][n]=='1')
                     {
                         q.push({m,n});
                         visited[m][n]=1;
                     }
                 }
                 q.pop();
             }
         }
         
         return count;
        
    }
};
