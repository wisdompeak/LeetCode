using AI3 = array<int,3>;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        vector<pair<int,int>>dir({{0,1},{0,-1},{1,0},{-1,0}});
        vector<pair<int,int>>qs;
        for (int i=0; i<queries.size(); i++)
            qs.push_back({queries[i], i});
        
        sort(qs.begin(), qs.end());
        
        vector<int>rets(queries.size());
        
        priority_queue<AI3, vector<AI3>, greater<>>pq;
        pq.push({grid[0][0], 0, 0});
        
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n));
        visited[0][0] = 1;
                
        for (auto [q, idx]: qs)
        {
            while (!pq.empty() && pq.top()[0] < q)
            {
                int i = pq.top()[1], j = pq.top()[2];
                pq.pop();
                count++;
                                
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (visited[x][y])
                        continue;
                    
                    pq.push({grid[x][y],x,y});
                    visited[x][y] = 1;
                }
            }            
            rets[idx] = count;
        }        
        return rets;        
    }
};
