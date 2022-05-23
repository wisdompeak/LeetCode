class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) 
    {
        if (stockPrices.size()==1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
        
        int ret = 1;
        int n = stockPrices.size();
        for (int i=2; i<n; i++)
        {
            if (!checkAlign(stockPrices, i))
                ret++;
        }
        return ret;        
    }
    
    bool checkAlign(vector<vector<int>>& stockPrices, int t)
    {
        int x0 = stockPrices[t-2][0], y0 = stockPrices[t-2][1];
        int x1 = stockPrices[t-1][0], y1 = stockPrices[t-1][1];
        int x2 = stockPrices[t-0][0], y2 = stockPrices[t-0][1];
        
        return (long long)(y2-y1)*(x1-x0)==(long long)(y1-y0)*(x2-x1);
    }
};
