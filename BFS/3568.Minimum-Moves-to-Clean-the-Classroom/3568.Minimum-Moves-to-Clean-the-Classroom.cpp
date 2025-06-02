using state = tuple<int,int,int,int>;
class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size(), n = grid[0].size();

        pair<int,int>start;
        vector<pair<int,int>>litter_pos;
        vector<vector<int>>litter_idx(m, vector<int>(n,-1));
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                if (grid[i][j]=='S')
                    start = {i,j};
                else if (grid[i][j]=='L')
                {                    
                    litter_pos.push_back({i,j});
                    litter_idx[i][j] = litter_pos.size()-1;
                }
            }    
        int L = litter_pos.size();

        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1, vector<bool>(1 << L, false))));        

        visited[start.first][start.second][energy][0] = true;

        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        queue<state> q;
        q.push({start.first, start.second, energy, 0});
        int step = 0;

        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto [x,y,e,mask] = q.front();
                q.pop();
                if (mask==(1<<L)-1) return step;

                for (int k=0; k<4; k++) 
                {
                    int nx = x+dir[k].first;
                    int ny = y+dir[k].second;
                    if (nx<0||nx>=m||ny<0||ny>=n) continue;
                    
                    char cell = grid[nx][ny];
                    if (cell=='X') continue;
                    
                    int newEnergy = e-1;
                    if (newEnergy < 0) continue;
                    if (cell == 'R') newEnergy = energy;

                    int newMask = mask;
                    if (grid[nx][ny]=='L')
                    {
                        int idx = litter_idx[nx][ny];
                        newMask |= (1<<idx);
                    }
                    if (!visited[nx][ny][newEnergy][newMask]) {
                        visited[nx][ny][newEnergy][newMask] = true;
                        q.emplace(nx, ny, newEnergy, newMask);
                    }    
                }                            
            }
            step++;
        }

        return -1;
    }
};
