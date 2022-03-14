using LL = long long;
using PII = pair<LL,LL>;

class Solution {
    int n;
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        this->n = n;
        vector<vector<PII>>next(n);
        vector<vector<PII>>prev(n);
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            next[a].push_back({b,w});
            prev[b].push_back({a,w});
        }
        
        vector<LL>AtoOthers = dijkstra(src1, next);
        vector<LL>BtoOthers = dijkstra(src2, next);
        vector<LL>CtoOthers = dijkstra(dest, prev);
        
        LL ret = LLONG_MAX/3;
        for (int i=0; i<n; i++)        
            ret = min(ret, AtoOthers[i]+BtoOthers[i]+CtoOthers[i]);    
            
        if (ret==LLONG_MAX/3)
            return -1;        
        else
            return ret;
    }
    
    vector<LL>dijkstra(int start, vector<vector<PII>>&adj)
    {
        vector<LL>dist(n, LLONG_MAX/3);            
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0,start});
        
        while (!pq.empty())
        {
            auto [d, c] = pq.top();
            pq.pop();
            if (dist[c] < LLONG_MAX/3)
                continue;            
            dist[c] = d;
            
            for (auto x: adj[c])
            {                
                LL nxt = x.first, len = x.second;
                if (dist[nxt] < LLONG_MAX/3) continue;
                pq.push({d+len, nxt});
            }
        }
        return dist;
    }    
};
