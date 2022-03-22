using AI3 = array<int,3>;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) 
    {
        vector<vector<pair<int,int>>>next(n);
        for (auto x: highways)
        {
            int a = x[0], b = x[1], w = x[2];
            next[a].push_back({b, w});
            next[b].push_back({a, w});
        }
        
        vector<vector<int>>cost(n, vector<int>(discounts+1, INT_MAX));  // cost[city][discounts]
        priority_queue<AI3, vector<AI3>, greater<>> pq; // {cost, city, discounts}
        pq.push({0,0,discounts});
        
        while (!pq.empty())
        {
            auto [c, cur, times] = pq.top();
            pq.pop();
            
            if (c >= cost[cur][times]) continue;
            cost[cur][times] = c;
            if (cur == n-1) return c;
            
            for (auto x: next[cur])
            {
                auto [nxt, toll] = x;
                if (cost[nxt][times]==INT_MAX)                    
                    pq.push({c+toll, nxt, times});
                if (times >= 1 && cost[nxt][times-1]==INT_MAX)
                    pq.push({c+toll/2, nxt, times-1});                
            }            
        }
        
        return -1;        
    }
};
