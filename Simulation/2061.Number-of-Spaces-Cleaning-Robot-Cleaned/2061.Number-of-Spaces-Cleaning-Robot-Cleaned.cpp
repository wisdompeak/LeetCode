class Solution {        
    int visited[300][300][4];
    int cleaned[300][300];
public:
    int numberOfCleanRooms(vector<vector<int>>& room) 
    {
        int m = room.size(), n = room[0].size();        
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = 0, y = 0, d = 0;
        int ret = 0;
        while (visited[x][y][d]==0)
        {
            if (cleaned[x][y]==0)
            {
                ret++;
                cleaned[x][y] = 1;                
            }
            
            visited[x][y][d]=1;
            
            int i = x+dir[d].first;
            int j = y+dir[d].second;
            if (i>=m||i<0||j>=n||j<0||room[i][j]==1)
            {
                d = (d+1)%4;                
            }
            else
            {
                x = i;
                y = j;
            }
        }
        return ret;        
    }
};
