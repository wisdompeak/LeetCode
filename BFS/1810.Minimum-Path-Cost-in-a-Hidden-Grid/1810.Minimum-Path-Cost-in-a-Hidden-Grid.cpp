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
        
        visited[100][100] = 1;
        dfs(master, 100, 100);
        
        for (int i=0; i<201; i++)
            for (int j=0; j<201; j++)
                visited[i][j] = 0;
                
        priority_queue<AI3,vector<AI3>, greater<>>pq;
        pq.push({0,100,100});
                
        while (!pq.empty())
        {
            auto [c,x,y] = pq.top();
            pq.pop();
            visited[x][y] = 1;        
            if (x==targetX && y==targetY)
                return c;
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (cost[i][j]==-1) continue;    
                if (i<0 || i>=200 || j<0|| j>=200) continue;
                if (visited[i][j]==1) continue;
                
                pq.push({c+cost[i][j], i, j});
            }
        }
        
        return -1;        
    }
    
    void dfs(GridMaster &master, int x, int y)
    {
        
        if (master.isTarget())
        {
            targetX = x;
            targetY = y;
        }
        for (int k=0; k<4; k++)
        {       
            int i = x+dir[k].first;
            int j = y+dir[k].second;
            if(visited[i][j]==1) continue;
            
            if (master.canMove(d[k]))
            {                
                int c = master.move(d[k]);
                visited[i][j] = 1;
                cost[i][j] = c;
                dfs(master, i,j);
                master.move(d[3-k]);
            }
            else
            {
                visited[i][j] = 1;                
            }
        }
    }
};
