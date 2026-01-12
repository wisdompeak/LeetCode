class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int ret = 0;
        for (int b=30; b>=0; b--) {
            int target = ret | (1<<b);
            vector<long long>costs;
            for (int i=0; i<n; i++) {
                long long num = nums[i];
                long long delta = 0;
                for (int p=30; p>=0; p--) {
                    if (((target>>p)&1) && (((num>>p)&1)==0)) {
                        long long mask = (1LL<<(p+1)) - 1;
                        long long r = num & mask;
                        delta = (target & mask)-(num & mask);                        
                        break;                        
                    }                    
                }
                costs.push_back(delta);
            }

            sort(costs.begin(), costs.end());
            long long sum  = 0 ;
            for (int i=0; i<m; i++) {
                sum += costs[i];
                if (sum > k) break;
            }
            if (sum <= k ) {
                ret = target;
            }            
        }
        return ret;
    }
};
