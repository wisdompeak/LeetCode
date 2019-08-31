class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int M = heightMap.size();
        if (M==0) return 0;
        int N = heightMap[0].size();
        
        set<vector<int>>Set;
        
        for (int i=0; i<M; i++)
        {
            Set.insert({heightMap[i][0],i,0});
            Set.insert({heightMap[i][N-1],i,N-1});
            heightMap[i][0] = -1;
            heightMap[i][N-1] = -1;
        }
        for (int j=0; j<N; j++)
        {
            Set.insert({heightMap[0][j],0,j});
            Set.insert({heightMap[M-1][j],M-1,j});
            heightMap[0][j] = -1;
            heightMap[M-1][j] = -1;
        }
        
        int ret = 0;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        while (!Set.empty())
        {
            int h = (*Set.begin())[0];
            int x = (*Set.begin())[1];
            int y = (*Set.begin())[2];
            Set.erase(Set.begin());
            
            queue<pair<int,int>>q;
            q.push({x,y});
            
            while (!q.empty())
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (int k=0; k<4; k++)
                {
                    int m = i+dir[k].first;
                    int n = j+dir[k].second;
                    
                    if (m<0||m>=M||n<0||n>=N)
                        continue;
                    if (heightMap[m][n]==-1)
                        continue;
                    
                    if (heightMap[m][n] <= h)
                    {
                        ret += h - heightMap[m][n];
                        q.push({m,n});
                        heightMap[m][n] = -1;
                    }
                    else
                    {
                        Set.insert({heightMap[m][n],m,n});
                        heightMap[m][n] = -1;
                    }
                        
                }
            }
        }
        return ret;
    }
};
