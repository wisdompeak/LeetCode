class Solution {
    int n;
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        n = prices.size();
        prices.insert(prices.begin(),0);
        int left = 0, right = *max_element(prices.begin(), prices.end());

        while (left<right)
        {
            int fee = left + (right-left)/2;
            if (helper(prices, fee)[1] > k)
                left = fee+1;
            else
                right = fee;
        }
        return helper(prices,left)[0] + left*k;
    }

    vector<int> helper(vector<int>& prices, int fee) 
    {
        vector<int>dp0(n+1,0);
        vector<int>dp1(n+1,0);
        dp0[0] = 0;
        dp1[0] = INT_MIN/2;
        int count0 = 0;
        int count1 = 0;

        for (int i=1; i<=n; i++)
        {
            if (dp1[i-1]+prices[i] - fee> dp0[i-1])
            {
                dp0[i] = dp1[i-1] + prices[i] - fee;
                count0 = count1+1;
            }
            else
                dp0[i] = dp0[i-1];
            
            if (dp0[i-1] - prices[i]  > dp1[i-1])
            {
                dp1[i] = dp0[i-1] - prices[i];
                count1 = count0;
            }
            else
                dp1[i] = dp1[i-1];
        }
        return {dp0[n], count0};
    }
};
