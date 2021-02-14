typedef vector<int> VI;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int m = heightMap.size();
        int n = heightMap[0].size();

        auto resolved = vector<vector<int>>(m, vector<int>(n+1));

        priority_queue<VI, vector<VI>, greater<>>pq;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (i==0 || i==m-1 || j==0 || j==n-1)
                    pq.push({heightMap[i][j],i,j});
            }

        int ret = 0;
        int cur = 0;        
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});


        while (!pq.empty())
        {
            int h = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if (resolved[x][y]) continue;
            resolved[x][y] = 1;

            cur = max(cur, h);
            ret += cur - h;
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=m||j<0||j>=n) continue;
                if (resolved[i][j]) continue;
                pq.push({heightMap[i][j],i,j});                
            }
        }
        return ret;        
    }
};
