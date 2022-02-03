using PII = pair<int,int>;
using AI3 = array<int,3>;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) 
    {
        vector<vector<PII>>next(n);
        for (auto x: highways)
        {
            next[x[0]].push_back({x[1], x[2]});
            next[x[1]].push_back({x[0], x[2]});
        }
                
        vector<vector<int>>dist(n, vector<int>(discounts+1, INT_MAX));
        
        priority_queue<AI3, vector<AI3>, greater<>>pq;        
        pq.push({0,0,discounts}); // {dist, node, discounts}
                
        while (!pq.empty())
        {
            auto [d, curNode, times] = pq.top();
            pq.pop();
            
            if (d >= dist[curNode][times]) continue;
            dist[curNode][times] = d;
            if (curNode==n-1) return d;
            
            for (auto nxt: next[curNode])
            {
                auto [nxtNode, len] = nxt;
                if (dist[nxtNode][times]!=INT_MAX) continue;                
                pq.push({d+len, nxtNode, times});
                if (times>=1)
                    pq.push({d+len/2, nxtNode, times-1}); 
            }
        }
        
        return -1;
        
    }
};
