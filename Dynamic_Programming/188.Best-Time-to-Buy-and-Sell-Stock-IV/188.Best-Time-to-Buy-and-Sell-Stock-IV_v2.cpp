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
        vector<int>sold(n+1,0);
        vector<int>hold(n+1,0);
        sold[0] = 0;
        hold[0] = INT_MIN/2;
        int count0 = 0;
        int count1 = 0;

        for (int i=1; i<=n; i++)
        {
            if (hold[i-1]+prices[i]> sold[i-1])
            {
                sold[i] = hold[i-1] + prices[i];
                count0 = count1+1;
            }
            else
                sold[i] = sold[i-1];
            
            if (sold[i-1] - prices[i] - fee  > hold[i-1])
            {
                hold[i] = sold[i-1] - prices[i] - fee;
                count1 = count0;
            }
            else
                hold[i] = hold[i-1];
        }
        return {sold[n], count0};
    }
};
