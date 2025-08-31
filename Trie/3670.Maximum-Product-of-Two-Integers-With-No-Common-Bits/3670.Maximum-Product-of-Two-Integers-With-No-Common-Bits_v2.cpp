class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max_n = *max_element(begin(nums), end(nums));
        int k = log2(max_n)+1;
        vector<int> dp(1<<k);
        for (int x : nums) 
            dp[x] = x;
        for (int b = 0; b < k; ++b)
            for (int mask = 0; mask < (1<<k); ++mask)
                if (mask & (1 << b))
                    dp[mask] = max(dp[mask], dp[mask - (1 << b)]);
        long long ans = 0;
        for (int n : nums)
            ans = max(ans, 1LL * n * dp[((1<<k)-1) ^ n]);
        return ans;       
    }
};
