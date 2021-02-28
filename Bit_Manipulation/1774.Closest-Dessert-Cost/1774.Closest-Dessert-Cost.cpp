class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) 
    {
        int cost;
        int diff = INT_MAX;
        int m = toppingCosts.size();
        
        for (int baseCost: baseCosts)
        {            
            for (int state = 0; state < (1<<(2*m)); state++)
            {
                int sum = baseCost;
                for (int i=0; i<m; i++)
                {
                    if ((state>>(i*2))&1)
                        sum += toppingCosts[i];
                    if ((state>>(i*2+1))&1)
                        sum += toppingCosts[i];
                }
                if (abs(sum-target)<diff || abs(sum-target)==diff && sum<cost)
                {
                    diff = abs(sum-target);
                    cost = sum;
                }
            }            
        }        
        return cost;        
    }
};
