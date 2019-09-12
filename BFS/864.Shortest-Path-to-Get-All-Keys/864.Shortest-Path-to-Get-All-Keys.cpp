class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        auto visited = vector<vector<unordered_set<int>>>(m,vector<unordered_set<int>>(n));
        
        queue<vector<int>>q;  // {x,y,state}
        int count = 0;
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]=='@')
                {
                    q.push({i,j,0});
                    visited[i][j].insert(0);
                }
                    
                else if (grid[i][j]>='a' && grid[i][j]<='f')
                    count++;
            }
        
        int finalState = 0;
        for (int i=0; i<count; i++)
            finalState |= (1<<i);
        
        int step = -1;
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        
        
        while (!q.empty())
        {
            step++;
            
            int len = q.size();            
            while (len--)
            {
                int x = q.front()[0];
                int y = q.front()[1];
                int state = q.front()[2];
                q.pop();
                
                for (int k=0; k<4; k++)
                {
                    int i = x + dir[k].first;
                    int j = y + dir[k].second;
                    int newState = state;
                    
                    if (i<0||i>=m||j<0||j>=n)
                        continue;
                    if (grid[i][j]=='#')
                        continue;
                    if (grid[i][j]>='A' && grid[i][j]<='F' && ((state>>(grid[i][j]-'A'))&1)==0)
                        continue;
                    
                    if (grid[i][j]>='a' && grid[i][j]<='f')
                        newState |= (1<<(grid[i][j]-'a'));
                    
                    if (visited[i][j].find(newState)!=visited[i][j].end())
                        continue;
                    
                    if (newState == finalState)
                        return step+1;
                    
                    q.push({i,j,newState});
                    visited[i][j].insert(newState);
                
                }
            }
            
        }
        
        return -1;
    }
};

