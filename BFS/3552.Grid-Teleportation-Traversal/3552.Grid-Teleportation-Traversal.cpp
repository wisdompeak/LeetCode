using pii = pair<int,int>;
const int INF = 1e9;

class Solution {
public:
    int minMoves(vector<string>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INF));
        deque<pii> dq;
        
        vector<vector<pii>> portals(26);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++){
                char c = grid[i][j];
                if(c >= 'A' && c <= 'Z')
                    portals[c - 'A'].push_back({i, j});
            }
        }
        vector<bool> used(26, false);

        dist[0][0] = 0;
        dq.push_back({0, 0});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!dq.empty()) 
        {
            auto [x,y] = dq.front(); 
            dq.pop_front();
            int cd = dist[x][y];
            if(x == m-1 && y == n-1) 
                return cd;

            char c = grid[x][y];
            if(c >= 'A' && c <= 'Z') 
            {
                int idx = c - 'A';
                if(!used[idx]) 
                {
                    used[idx] = true;
                    for(auto [nx, ny] : portals[idx]) 
                    {
                        if(dist[nx][ny] > cd) {
                            dist[nx][ny] = cd;
                            dq.push_front({nx, ny});
                        }
                    }
                }
            }
            
            for(auto &d : dirs) 
            {
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(grid[nx][ny] == '#') continue;
                if(dist[nx][ny] > cd + 1) {
                    dist[nx][ny] = cd + 1;
                    dq.push_back({nx, ny});
                }
            }
        }

        return -1;        
    }
};
