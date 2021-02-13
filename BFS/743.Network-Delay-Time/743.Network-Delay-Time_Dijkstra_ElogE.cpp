typedef pair<int,int> PII;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int K) 
    {        
        vector<vector<PII>>Map(n+1);
        for (auto t: times)
            Map[t[0]].push_back({t[1], t[2]});
            
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0, K});
        vector<int>resolved(n+1,0);
        int ret = 0;
        
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            
            if (resolved[cur]==1) continue;
            resolved[cur] = 1;
            ret = max(ret, d);  // dist[cur] = d
            
            for (auto [next, weight]: Map[cur])
            {
                if (resolved[next]) continue;
                pq.push({d+weight, next});
            }            
        }
        
        for (int i=1; i<=n; i++)
            if (resolved[i]==0) return -1;
        
        return ret;
    }
};
