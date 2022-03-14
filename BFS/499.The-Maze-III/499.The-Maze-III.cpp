using TP = tuple<int,string,int,int>;
class Solution {
private:
    int m,n;
    vector<pair<int,int>> dir={{1,0},{0,-1},{0,1},{-1,0}};
    
public:
    int Next(int i, int j, vector<vector<int>>& maze, int k, vector<int>& hole)
    {        
        int steps=0;
        while (i+dir[k].first>=0 && i+dir[k].first<m && j+dir[k].second>=0 && j+dir[k].second<n && maze[i+dir[k].first][j+dir[k].second]!=1)
        {
            i += dir[k].first;
            j += dir[k].second;
            steps++;            
            if (i==hole[0] && j==hole[1])
                break;
        }
        return steps;
    }
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) 
    {
        m = maze.size();
        n = maze[0].size();
        
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        vector<vector<string>>inst(m, vector<string>(n, "z"));
        
        priority_queue<TP, vector<TP>, greater<>> pq;
        pq.push({0, "", ball[0], ball[1]});
        
        while (!pq.empty())
        {
            auto [d, s, x, y] = pq.top();
            pq.pop();
            
            if (d > dist[x][y]) continue;            
            dist[x][y] = d;
            inst[x][y] = min(inst[x][y], s);
                        
            if (x==hole[0] && y==hole[1]) continue;
            
            for (int k=0; k<4; k++)
            {                
                int step = Next(x,y,maze,k,hole);
                int i = x+dir[k].first*step;
                int j = y+dir[k].second*step;

                char ch='0'+k;
                if (d+step > dist[i][j]) continue;
                if (d+step == dist[i][j] && (s+ch) >= inst[i][j]) continue;
                pq.push({d+step, s+ch, i, j});
            }
        }
        
        if (dist[hole[0]][hole[1]]==INT_MAX)
            return "impossible";
        
        string ret = inst[hole[0]][hole[1]];
        for (int i=0; i<ret.size(); i++)
        {
            if (ret[i]=='0') ret[i] = 'd';
            else if (ret[i]=='1') ret[i] = 'l';
            else if (ret[i]=='2') ret[i] = 'r';
            else if (ret[i]=='3') ret[i] = 'u';
        }
        
        return ret;
        
    }
};
