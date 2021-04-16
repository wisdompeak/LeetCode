typedef array<int,3> AI3;
class Solution {    
    int visited[100][100];
    vector<pair<int,int>> next[100];
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) 
    {
        priority_queue<AI3, vector<AI3>, greater<>>pq; // {cost, i, battery}
        pq.push({0, start, 0});
        int n = charge.size();        

        for (auto path: paths)
        {
            next[path[0]].push_back({path[1], path[2]});
            next[path[1]].push_back({path[0], path[2]});
        }

        while (!pq.empty())
        {
            auto [cost, cur, battery] = pq.top();
            pq.pop();
            if (visited[cur][battery]==1) continue;
            visited[cur][battery] = 1;

            if (cur==end) return cost;

            for (int b=battery+1; b<=cnt; b++)
            {
                if (visited[cur][b]==1) continue;
                pq.push({cost+(b-battery)*charge[cur], cur, b});
            }
                
            for (auto [nxt, len]: next[cur])
            {
                if (battery < len) continue;
                if (visited[nxt][battery-len]) continue;
                pq.push({cost + len, nxt, battery - len});
            }
        }

        return 0;
    }
};
