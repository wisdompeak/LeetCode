typedef array<int,3> AI3;
class Solution {        
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) 
    {
        int n = passingFees.size();
        vector<vector<int>>dp(n, vector<int>(maxTime+1,INT_MAX/2));
        vector<int>earliestTime(n+1, INT_MAX/2);
        vector<int>smallestFee(n+1, INT_MAX/2);
                        
        vector<pair<int,int>> next[1001];
        for (auto edge: edges)
        {
            next[edge[0]].push_back({edge[1], edge[2]});
            next[edge[1]].push_back({edge[0], edge[2]});
        }
                        
        queue<pair<int,int>>q;
        dp[0][0] = passingFees[0];
        q.push({0, 0});        
        
        while (!q.empty())
        {
            auto [city, time] = q.front();
            int fee = dp[city][time];
            q.pop();
            
            for (auto [nxt, t]: next[city])
            {
                int newTime = time + t;
                int newFee = fee + passingFees[nxt];                
                
                if (newTime > maxTime) continue;
                if (newTime > earliestTime[nxt] && newFee > dp[nxt][earliestTime[nxt]])
                    continue;
                
                if (newFee < dp[nxt][newTime])
                {                    
                    dp[nxt][newTime] = newFee;
                    q.push({nxt, newTime});
                    earliestTime[nxt] = min(earliestTime[nxt], newTime);
                }
            }
        }
        
        int ret = INT_MAX/2;
        for (int t=0; t<=maxTime; t++)
            ret = min(ret, dp[n-1][t]);
        
        if (ret>=INT_MAX/2)
            return -1;
        else
            return ret;
    }
};
