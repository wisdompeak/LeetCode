 class Solution {
    int dp[42][100006];
public:
    int minRemovals(vector<int>& nums, int target) {
        int  n = nums.size();
        nums.insert(nums.begin(), 0);        
        for (int v=0; v<100000; v++)
            dp[0][v] = INT_MIN/2;
        dp[0][0] = 0;

        for (int i=1; i<=n; i++)
            for (int v=0; v<(1<<14); v++) {
                dp[i][v] = max(dp[i-1][v], dp[i-1][v^nums[i]]+1);
            }                

        if (dp[n][target] < 0)
            return -1;
        else
            return n - dp[n][target];
    }
};
