using PII = pair<int,int>;
class Solution {
    vector<PII>next[50005];
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) 
    {
        vector<int>rets(n, -1);
        
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            next[a].push_back({b,w});
            next[b].push_back({a,w});
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0, 0});        
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (rets[cur]!=-1) continue;
            rets[cur] = dist;                

            for (auto [nxt, len]: next[cur])
            {
                if (rets[nxt]!=-1) continue;
                if (dist + len >= disappear[nxt]) continue;
                pq.push({dist + len, nxt});
            }
        }
        
        return rets;
    }
};
