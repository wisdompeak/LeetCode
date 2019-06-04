class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        
        if (k>=n/2)
        {
            int result = 0;
            for (int i=1; i<prices.size(); i++)
                if (prices[i]>prices[i-1])
                    result+=prices[i]-prices[i-1];
            return result;
        }
        
        vector<int>hold(k+1, INT_MIN/2);
        vector<int>sold(k+1, INT_MIN/2);
        
        hold[0] = 0;
        sold[0] = 0;
        
        for (int i=0; i<n; i++)
        {
            auto hold_old = hold;
            auto sold_old = sold;
            
            for (int j=1; j<=k; j++)
            {
                hold[j] = max (sold_old[j-1]-prices[i], hold_old[j] );
                sold[j] = max (hold_old[j]+prices[i], sold_old[j] );
            }
            
        }
        
        int result = INT_MIN;
        for (int j=0; j<=k; j++)
            result = max(result, sold[j]);
        return result;
    }
};
