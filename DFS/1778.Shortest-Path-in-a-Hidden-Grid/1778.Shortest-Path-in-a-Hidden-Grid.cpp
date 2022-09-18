/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

typedef pair<int,int> PII;

class Solution {
    int grid[1001][1001];    
    int visited[1001][1001];
    int visited2[1001][1001];
    vector<PII> dir{{-1,0},{1,0},{0,-1},{0,1}};
    vector<char> move{'U','D','L','R'};
public:
    int findShortestPath(GridMaster &master) 
    {   
        visited[500][500] = 1;
        dfs(500, 500, master);
                
        queue<PII>q;
        q.push({500,500});
        visited2[500][500]=1;        
        
        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            step++;
            while (len--)
            {
                auto [i,j] = q.front();
                q.pop();
                
                for (int k=0; k<4; k++)
                {                    
                    int x = i + dir[k].first;
                    int y = j + dir[k].second;
                    if (grid[x][y]==2) return step;                        
                    if (grid[x][y]==0) continue;
                    if (visited2[x][y]==1) continue;
                        
                    visited2[x][y] = 1;
                    q.push({x,y});                        
                }
            }
        }
        return -1;
        
    }
    
    void dfs(int i, int j, GridMaster &master)
    {
        
        grid[i][j] = 1;
        
        if (master.isTarget())
        {
            grid[i][j] = 2;
            return;
        }
        
        for (int k=0; k<4; k++)
        {
            int x = i+dir[k].first;
            int y = j+dir[k].second;
            if (visited[x][y]) continue;
            
            if (master.canMove(move[k])==false)
                grid[x][y] = 0;
            else 
            {
                visited[x][y] = 1;
                master.move(move[k]);
                
                dfs(x,y,master);                
                
                int kk;
                if (k==0) kk=1;
                else if (k==1) kk=0;
                else if (k==2) kk=3;
                else if (k==3) kk=2;
                master.move(move[kk]);
            }                
        }
    }
};
