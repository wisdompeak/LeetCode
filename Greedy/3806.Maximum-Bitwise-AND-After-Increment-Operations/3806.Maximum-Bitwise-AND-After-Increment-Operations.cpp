class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int ret = 0;
        for (int b=30; b>=0; b--) {
            int candidate = ret | (1<<b);
            vector<long long>costs;
            for (int i=0; i<n; i++) {
                long long num = nums[i];
                for (int p=30; p>=0; p--) {
                    if (((candidate>>p)&1) && (((num>>p)&1)==0)) {
                        long long mask = (1LL<<(p+1)) - 1;
                        long long r = num & mask;
                        long long delta = (1LL<<p)-r;
                        num += delta;
                    }                    
                }
                costs.push_back(num-nums[i]);
            }

            sort(costs.begin(), costs.end());
            long long sum  = 0 ;
            for (int i=0; i<m; i++) {
                sum += costs[i];
                if (sum > k) break;
            }
            if (sum <= k ) {
                ret = candidate;
            }            
        }
        return ret;
    }
};
