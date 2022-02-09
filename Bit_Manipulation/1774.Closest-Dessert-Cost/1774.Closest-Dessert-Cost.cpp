class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        unordered_set<int> toppingsSet;

        int n = toppingCosts.size();

        for(int state = 0; state < (1 << (2 * n)); ++state) {
            int sum = 0;
            for(int i = 0; i < n; ++i) {
                int cur = (state >> (2 * i)) & 3;
                if(!cur || cur == 3) continue;
                sum += toppingCosts[i] * cur;
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
