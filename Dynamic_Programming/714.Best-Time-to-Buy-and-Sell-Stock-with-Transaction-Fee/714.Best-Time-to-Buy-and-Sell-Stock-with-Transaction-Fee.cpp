class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if (prices.size()==1) return 0;
        
        int s0=0;
        int s1=-prices[0];
        
        for (int i=1; i<prices.size(); i++)
        {
            int temp = s0;
            s0 = max(s0, s1+prices[i]-fee);
            s1 = max(temp-prices[i],s1);
        }                
        
        return s0;
    }
};
