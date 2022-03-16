using AI3 = array<int,3>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<pair<int,int>>>next(n);        
        for (auto flight: flights)
        {
            int a = flight[0], b = flight[1], w = flight[2];
            next[a].push_back({b, w});
        }            

        vector<vector<int>>cost(n, vector<int>(K+2, INT_MAX/2));
        priority_queue<AI3, vector<AI3>, greater<>>pq;
        pq.push({0, src, 0});        

        while (!pq.empty())
        {
            auto [c, cur, stops] = pq.top();
            pq.pop();
            
            if (cur == dst) return c;
            if (stops == K+1) continue;
            if (cost[cur][stops] < INT_MAX/2) continue;                       
            cost[cur][stops] = c;

            for (auto ticket: next[cur])
            {
                auto [nxt, price] = ticket;
                if (cost[nxt][stops+1] < INT_MAX/2) continue;
                pq.push({c+price, nxt, stops+1});
            }
        }

        return -1;        
    }
};
