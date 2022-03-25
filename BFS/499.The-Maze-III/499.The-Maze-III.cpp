using TP = tuple<int, string, int, int>;
class Solution {
    vector<pair<int,int>>dir = {{1,0},{0,-1},{0,1},{-1,0}};  // d,l,r,u
    int m,n;
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) 
    {
        m = maze.size(), n = maze[0].size();
        
        priority_queue<TP, vector<TP>, greater<>>pq;  // {dist, string, node_x, node_y}
        pq.push({0, "", ball[0], ball[1]});
        
        vector<vector<int>>dist(m, vector<int>(n,INT_MAX)); 
        string ret;
        
        while (!pq.empty())
        {
            auto [d, s, x, y] = pq.top();
            pq.pop();
            
            if (d > dist[x][y]) continue;
            else dist[x][y] = d;
            
            if (x==hole[0] && y==hole[1])
            {
                ret = s;
                break;
            }
            
            for (int k=0; k<4; k++)
            {
                int step = Next(x,y,k,maze, hole);
                int i = x + dir[k].first * step;
                int j = y + dir[k].second * step;
                
                char ch = '0'+k;
                if (d+step >= dist[i][j]) continue;
                pq.push({d+step, s+ch, i, j});
            }            
        }
        
        for (int i=0; i<ret.size(); i++)
        {
            if (ret[i]=='0') ret[i] = 'd';
            else if (ret[i]=='1') ret[i] = 'l';
            else if (ret[i]=='2') ret[i] = 'r';
            else if (ret[i]=='3') ret[i] = 'u';
        }
        
        if (ret=="") return "impossible";
        else return ret;        
    }
    
    int Next(int x, int y, int k, vector<vector<int>>& maze, vector<int>& hole)
    {
        int step = 0;
        while (x+dir[k].first >= 0 && x+dir[k].first < m && y+dir[k].second >= 0 && y+dir[k].second < n && maze[x+dir[k].first][y+dir[k].second]!=1)
        {            
            step++;
            x+=dir[k].first;
            y+=dir[k].second;
            if (x==hole[0] && y==hole[1])
                break;
        }
        return step;
    }
};
