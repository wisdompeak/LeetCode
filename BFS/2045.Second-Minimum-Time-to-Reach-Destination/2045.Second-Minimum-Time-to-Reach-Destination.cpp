using PII = pair<int,int>;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        vector<vector<int>>next(n+1);
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0,1});
        vector<int>arrival1(n+1, -1);
        vector<int>arrival2(n+1, -1);

        while (!pq.empty())
        {
            auto [t, cur] = pq.top();
            pq.pop();
            if (arrival2[cur]!=-1)
                continue;
            else if (arrival1[cur]!=-1 && t > arrival1[cur])
                arrival2[cur] = t;
            else if (arrival1[cur]==-1)
                arrival1[cur] = t;

            if (cur==n && arrival2[cur]!=-1)
                return arrival2[cur];

            int tt;
            if ((t/change)%2 == 0)
                tt = t+time;
            else
                tt = ((t-1)/(2*change)+1)*(2*change) + time;

            for (int nxt: next[cur])
            {
                if (arrival2[nxt]!=-1) continue;
                pq.push({tt, nxt});
            }
        }

        return -1;        
    }
};
