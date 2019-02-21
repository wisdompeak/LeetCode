class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int>dp(400,INT_MAX);
        vector<int>day(400,0);
        for (auto a:days) day[a]=1;
        
        int start = 1;
        while (start<=365 && day[start]==0)
            start++;
        if (start>365) return 0;
        
        dp[start] = 0;
        
        for (int i=start; i<=365; i++)
        {
            if (dp[i]==INT_MAX) continue;            
            int next;
            
            next = i+1;
            while (next<=365 && day[next]==0)
                next++;
            dp[next] = min(dp[next], dp[i]+costs[0]);
            
            next = i+7;
            while (next<=365 && day[next]==0)
                next++;
            dp[next] = min(dp[next], dp[i]+costs[1]);
            
            next = i+30;
            while (next<=365 && day[next]==0)
                next++;
            dp[next] = min(dp[next], dp[i]+costs[2]);
        }
        
        int result = INT_MAX;
        for (int i=366; i<=366+7; i++)
            result = min(result,dp[i]);
        return result;
    }
};
