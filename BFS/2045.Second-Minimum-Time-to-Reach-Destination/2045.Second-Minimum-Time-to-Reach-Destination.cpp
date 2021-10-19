using PII = pair<int,int>;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        vector<int>next[n+1];
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }        
        
        vector<int>visited(n+1,0);
        vector<int>dist(n+1,-1);
        queue<PII>q;
        q.push({1,0});
        dist[1] = 0;

        while (!q.empty())
        {
            auto [cur, t] = q.front();
            q.pop();

            int tt;
            int round = t/change;
            if (round%2==0)
                tt = t+time;
            else
                tt = (round+1)*change + time;

            for (int nxt: next[cur])
            {
                if (visited[nxt]<2 && dist[nxt] < tt)
                {
                    dist[nxt] = tt;
                    visited[nxt]+=1;
                    q.push({nxt, tt});

                    if (visited[nxt]==2 && nxt==n)
                        return tt;
                }
            }
        }
        return -1;        
    }
};
