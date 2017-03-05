class Solution {
private:
    int M;
    int N;
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        M=heightMap.size();
        if (M==0) return 0;
        N=heightMap[0].size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        for (int i=0; i<M; i++)
          for (int j=0; j<N; j++)
          {
              if (i==0 || i==M-1 || j==0 || j==N-1)
              {
                 q.push({heightMap[i][j],i*N+j});
                 visited[i][j]=1;
              }
          }
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        int result=0;
        while (!q.empty())
        {
            int i=q.top().second/N;
            int j=q.top().second%N;
            int seaLevel=q.top().first;
            q.pop();
            
            queue<pair<int,int>>p;
            p.push({i,j});

            while (!p.empty())
            {
                int m=p.front().first;
                int n=p.front().second;
                p.pop();
                
                for (int k=0; k<4; k++)
                {
                    int x=m+dir[k].first;
                    int y=n+dir[k].second;
                    
                    if (x<0 || x>M-1 || y<0 || y>N-1) continue;
                    
                    if (visited[x][y]==1) continue;
                    
                    if (heightMap[x][y]<seaLevel)
                    {
                        result+=seaLevel-heightMap[x][y];
                        p.push({x,y});
                    }
                    else
                    {
                        q.push({heightMap[x][y],x*N+y});
                    }
                    
                    visited[x][y]=1;
                    
                }
            }
            
        }
        
        return result;
        
    }
};
