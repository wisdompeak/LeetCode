using PII = pair<int,int>;

class Solution {
    vector<array<int,3>>next[50005];
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
        int m = edges.size();
        vector<bool>rets(m, false);
        
        for (int i=0; i<m; i++)
        {
            auto& edge = edges[i];
            int a = edge[0], b = edge[1], w = edge[2];
            next[a].push_back({b,w, i});
            next[b].push_back({a,w, i});
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        
        pq.push({0, 0});        
        vector<int>d1(n, INT_MAX/2);
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (d1[cur]!= INT_MAX/2) continue;
            d1[cur] = dist;                

            for (auto [nxt, len, idx]: next[cur])
            {
                if (d1[nxt]!= INT_MAX/2) continue;                
                pq.push({dist + len, nxt});
            }
        }
        
        while (!pq.empty()) pq.pop();        
        pq.push({0, n-1});        
        vector<int>d2(n, INT_MAX/2);
        while (!pq.empty()) 
        {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (d2[cur]!= INT_MAX/2) continue;
            d2[cur] = dist;

            for (auto [nxt, len, idx]: next[cur])
            {
                if (d2[nxt]!= INT_MAX/2) continue;                
                pq.push({dist + len, nxt});
                
                if (dist+len + d1[nxt] == d1[n-1])
                    rets[idx] = true;
            }
        }
                
        return rets;
        
    }
};
