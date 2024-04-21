using PII = pair<int,int>;

class Solution {
    vector<PII>next[50005];
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        vector<bool>rets(m, false);
        
        for (auto& edge : edges)
        {
            int a = edge[0], b = edge[1], w = edge[2];
            next[a].push_back({b,w});
            next[b].push_back({a,w});
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        
        pq.push({0, 0});        
        vector<int>d1(n, INT_MAX/3);
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (d1[cur]!= INT_MAX/3) continue;
            d1[cur] = dist;                

            for (auto [nxt, len]: next[cur])
            {
                if (d1[nxt]!= INT_MAX/3) continue;                
                pq.push({dist + len, nxt});
            }
        }
        
        pq.push({0, n-1});        
        vector<int>d2(n, INT_MAX/3);
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (d2[cur]!= INT_MAX/3) continue;
            d2[cur] = dist;

            for (auto [nxt, len]: next[cur])
            {
                if (d2[nxt]!= INT_MAX/3) continue;                
                pq.push({dist + len, nxt});
            }
        }

        for (int i=0; i<m; i++)
        {
            auto& edge = edges[i];
            int a = edge[0], b = edge[1], w = edge[2];
            if (d1[a]+w+d2[b]==d1[n-1] || d1[b]+w+d2[a]==d1[n-1])
                rets[i] = true;
        }
                
        return rets;        
    }
};
