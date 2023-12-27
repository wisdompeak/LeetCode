class Solution {
    int dp[100005][2];
public:
    int minimumCoins(vector<int>& prices) 
    {
        int n = prices.size();
        prices.insert(prices.begin(), 0);
        dp[1][0] = INT_MAX/2;
        dp[1][1] = prices[1];

        deque<int>dq;   
        dq.push_back(1);     
        
        for (int i=2; i<=n; i++)
        {
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + prices[i];
            while (!dq.empty() && dq.front()*2<i)
                dq.pop_front();
            dp[i][0] = dp[dq.front()][1];

            while (!dq.empty() && dp[dq.back()][1] >= dp[i][1])
                dq.pop_back();
            dq.push_back(i);            
        }

        return min(dp[n][0], dp[n][1]);
        
    }
};
