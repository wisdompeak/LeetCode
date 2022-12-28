using LL = long long;
using PII = pair<int,LL>;
class Solution {
    vector<PII>next[1005];
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) 
    {
        for (auto& road: roads)
        {
            int a = road[0], b = road[1], c = road[2];
            next[a].push_back({b,c});
            next[b].push_back({a,c});
        }

        vector<LL>rets;
        for (int i=1; i<=n; i++)
        {
            priority_queue<PII, vector<PII>, greater<>>pq;
            pq.push({0, i});
            vector<LL>visited(n+1, -1);
            while (!pq.empty()) 
            {
                auto [dist, cur] = pq.top();
                pq.pop();
                if (visited[cur] == -1)                
                    visited[cur] = dist;
                
                for (auto [nxt, len]: next[cur])
                {
                    if (visited[nxt]!=-1) continue;
                    pq.push({dist + len*(1+k), nxt});
                }
            }

            LL ret = LLONG_MAX;
            for (int i=1; i<=n; i++)
                if (visited[i]!=-1)
                    ret = min(ret, appleCost[i-1]+visited[i]);
            rets.push_back(ret);
        }

        return rets;
    }
};
