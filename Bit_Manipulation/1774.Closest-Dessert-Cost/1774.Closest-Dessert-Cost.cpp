class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        set<int> toppingsSet;

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
        
        int ret = INT_MAX;
        for(int base: baseCosts) {
            int targetTopping = target - base;

            auto it1 = toppingsSet.upper_bound(targetTopping);
            auto it2 = it1;
            if(it2 != toppingsSet.begin()) --it2;
            if(it1 == toppingsSet.end()) --it1;
            int cur;
            int curDiff1 = abs(*it1 + base - target);
            int curDiff2 = abs(*it2 + base - target);
            if(curDiff1  < curDiff2) {
                cur = *it1 + base;
            } else {
                cur = *it2 + base;
            }
            int retDiff = abs(ret - target);
            int curDiff = abs(cur - target);
            if(curDiff < retDiff || (curDiff == retDiff && cur < ret)) ret = cur;
        }
        return ret;
    }
};
