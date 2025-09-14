class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(k+1,0);
        dp[0] = 1;
        vector<bool>rets(n, 0);
        
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int x=1; x<=n; x++) {
            while (i<n && nums[i]<x) {
                for (int c = k; c>=1; c--) {
                    if (c<nums[i]) break;
                    dp[c] |= dp[c-nums[i]];                
                }
                i++;
            }
            int m = n-i;
            for (int j=0; j<=m && j*x<=k; j++) {
                if (dp[k-j*x]) {
                    rets[x-1] = 1;
                    break;
                }
            }
        }
        return rets;
    }
};
