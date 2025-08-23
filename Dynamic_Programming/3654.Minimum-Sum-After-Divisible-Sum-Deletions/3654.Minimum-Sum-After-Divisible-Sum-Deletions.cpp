using ll = long long;
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);

        vector<ll>dp(n+1,LLONG_MAX/4);
        vector<ll>dp_by_r(k,LLONG_MAX/4);
        dp[0] = 0;
        dp_by_r[0] = 0;

        ll presum = 0;
        for (int i=1; i<=n; i++) {
            presum += nums[i];
            int r = presum % k;
            dp[i] = min(dp[i-1] + nums[i], dp_by_r[r]);
            dp_by_r[r] = min(dp_by_r[r], dp[i]);
        }        
        
        return dp[n];
    }
};
