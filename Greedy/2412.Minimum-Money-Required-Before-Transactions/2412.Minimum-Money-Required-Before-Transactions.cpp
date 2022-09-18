using LL = long long;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) 
    {
        sort(transactions.begin(), transactions.end(), [](vector<int>&a, vector<int>&b){return a[1]<b[1];});
        LL maxCostForNetGain = 0;
        
        LL cur = 0;
        LL histLow = 0;
        
        for (auto& trans: transactions)
        {
            LL cost = trans[0], back = trans[1];
            if (cost <= back)
            {
                maxCostForNetGain = max(maxCostForNetGain, cost);                
            }
            else
            {
                cur -= cost;
                histLow = min(histLow, cur);
                cur += back;
            }
        }
        
        cur -= maxCostForNetGain;
        histLow = min(histLow, cur);
        
        return abs(histLow);
    }
};
