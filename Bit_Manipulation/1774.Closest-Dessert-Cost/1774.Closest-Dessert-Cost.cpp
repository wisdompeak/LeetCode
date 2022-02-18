class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int m = toppingCosts.size();
        
        unordered_set<int> toppingsSet;        
        for(int state = 0; state < pow(3,m); ++state) 
        {
            int s = state;
            int sum = 0;
            for(int i = 0; i < m; ++i) 
            {
                int cur = s%3;                
                sum += toppingCosts[i] * cur;
                s/=3;
            }
            toppingsSet.insert(sum);
        }
        vector<int>toppings(toppingsSet.begin(), toppingsSet.end());
        sort(toppings.begin(), toppings.end());
        
        int ret = INT_MAX;
        int ret_diff = INT_MAX;
        for(int base: baseCosts) {
            int targetTopping = target - base;

            auto iter = lower_bound(toppings.begin(), toppings.end(), targetTopping);
            if (iter!=toppings.end())
            {
                int cand = *iter;
                if (abs(base+cand-target) < ret_diff)
                {
                    ret = base+cand;
                    ret_diff = abs(base+cand-target);
                }                    
                else if (abs(base+cand-target) == ret_diff && base+cand < ret)
                    ret = base+cand;                    
            }
            
            if (iter!=toppings.begin())
            {
                int cand = *prev(iter);
                if (abs(base+cand-target) < ret_diff)
                {
                    ret = base+cand;
                    ret_diff = abs(base+cand-target);
                }                    
                else if (abs(base+cand-target) == ret_diff && base+cand < ret)
                    ret = base+cand;                    
            }            
        }
        
        return ret;
    }
};
