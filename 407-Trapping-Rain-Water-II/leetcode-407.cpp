class Solution {
public:
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            return (a.first>b.first);
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int M=heightMap.size();
        if (M==0) return 0;
        int N=heightMap[0].size();
        
        auto dir=vector<pair<int,int>>{{-1,0},{1,0},{0,1},{0,-1}};
        auto visited=vector<vector<int>>(M,vector<int>(N,0));
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
        for (int i=0; i<M; i++)
        {
            q.push({heightMap[i][0],i*N+0});
            q.push({heightMap[i][N-1],i*N+N-1});
            visited[i][0]=1;
            visited[i][N-1]=1;
        }
        for (int j=1; j<N-1; j++)
        {
            q.push({heightMap[0][j],0*N+j});
            q.push({heightMap[M-1][j],(M-1)*N+j});
            visited[0][j]=1;
            visited[M-1][j]=1;
        }
        
        int sum=0;
        
        while (!q.empty())
        {
            int level = q.top().first;
            int i=q.top().second /N;
            int j=q.top().second %N;
            q.pop();
            
            queue<pair<int,int>>flood;
            flood.push({i,j});
            
            while (!flood.empty())
            {
                int m=flood.front().first;
                int n=flood.front().second;
                flood.pop();
                
                for (int k=0; k<4; k++)
                {
                    int mm = m+dir[k].first;
                    int nn = n+dir[k].second;
                    
                    if (mm<0 || mm==M || nn<0 || nn==N) continue;
                    if (visited[mm][nn]==1) continue;
                    
                    if (heightMap[mm][nn]>=level)
                    {
                        q.push({heightMap[mm][nn],mm*N+nn});
                        visited[mm][nn]=1;
                    }
                    else
                    {
                        flood.push({mm,nn});
                        sum+=level-heightMap[mm][nn];
                        visited[mm][nn]=1;
                    }
                }
            }
            
        }
        
        return sum;
        
    }
};
