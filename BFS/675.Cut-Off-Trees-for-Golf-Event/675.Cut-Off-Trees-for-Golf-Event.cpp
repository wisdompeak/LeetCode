class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) 
    {
        map<int,pair<int,int>>Map;
        int M=forest.size();
        int N=forest[0].size();
        
        for (int i=0; i<M; i++)
         for (int j=0; j<N; j++)
         {
             if (forest[i][j]>1)            
                 Map[forest[i][j]]={i,j};             
         }
        
        int x=0;
        int y=0;
        int result=0;
        for (auto a:Map)
        {
            int m=a.second.first;
            int n=a.second.second;
            
            int step=Go(x,y,m,n,forest);
            if (step==-1) return -1;
            else result+=step;
            x=m;
            y=n;
        }
        
        return result;
            
    }
    
    int Go(int x0, int y0, int m, int n, vector<vector<int>>& forest)
    {
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        int M=forest.size();
        int N=forest[0].size();
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        
        queue<pair<int,int>>q;
        q.push({x0,y0});
        visited[x0][y0]=1;
        int count=-1;
        
        while (!q.empty())
        {
            int num=q.size();
            count++;
            
            for (int i=0; i<num; i++)
            {
                int x=q.front().first;
                int y=q.front().second;                
                q.pop();
                if (x==m && y==n) return count;                
                                
                for (int k=0; k<4; k++)
                {
                    int a=x+dir[k].first;
                    int b=y+dir[k].second;
                    if (a<0 || a>=M || b<0 || b>=N) continue;
                    if (forest[a][b]==0) continue;
                    if (visited[a][b]==1) continue;
                    q.push({a,b});
                    visited[a][b]=1;
                }
            }
        }
        
        return -1;
        
    }
};
