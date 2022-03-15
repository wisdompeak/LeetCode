/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     int move(char direction);
 *     boolean isTarget();
 * };
 */
typedef array<int,3> AI3;

class Solution {
    int visited[201][201];
    int cost[201][201];
    string d = "ULRD";
    int targetX, targetY;
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    
public:
    int findShortestPath(GridMaster &master) 
    {
        for (int i=0; i<201; i++)
            for (int j=0; j<201; j++)
                cost[i][j] = -1;
        
        int x0 = 100, y0 = 100;
        dfs(master, x0, y0);
        return dijkstra(x0, y0);
    }
    
    void dfs(GridMaster &master, int x, int y)
    {
        if(visited[x][y]==1) return;
        visited[x][y] = 1;
        
        if (master.isTarget())
        {
            targetX = x;
            targetY = y;
        }
        
        for (int k=0; k<4; k++)
        {       
            if (master.canMove(d[k]))
            {                
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                cost[i][j] = master.move(d[k]);
                dfs(master, i,j);
                master.move(d[3-k]);
            }            
        }
    }
    
    int dijkstra(int x0, int y0)
    {
        vector<vector<int>>visited(201, vector<int>(201));        
        priority_queue<AI3,vector<AI3>, greater<>>pq;
        pq.push({0,x0,y0});
                
        while (!pq.empty())
        {
            auto [c,x,y] = pq.top();
            pq.pop();
            if (visited[x][y]==1) continue;
            visited[x][y] = 1;        
            if (x==targetX && y==targetY)
                return c;
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0 || i>=200 || j<0|| j>=200) continue;
                if (cost[i][j]==-1) continue;                    
                if (visited[i][j]==1) continue;
                
                pq.push({c+cost[i][j], i, j});
            }
        }
        
        return -1;  
    }
    
};
