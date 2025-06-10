class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long M = 1e9+7;
        nums.insert(nums.begin(), 0);
        
        vector<long>dp(n+1);
        vector<long>presum(n+1);
        dp[0] = 1;
        presum[0] = 1;

        deque<int>dq1;
        deque<int>dq2;
        int left = 1;
        for (int i=1; i<=n; i++) {
            int x = nums[i];
            while (!dq1.empty() && nums[dq1.back()]<x) {
                dq1.pop_back();
            }
            dq1.push_back(i);
            while (!dq2.empty() && nums[dq2.back()]>x) {
                dq2.pop_back();
            }
            dq2.push_back(i);

            while (left <= i && nums[dq1.front()] - nums[dq2.front()] > k) {
                if (dq1.front()==left) dq1.pop_front();
                if (dq2.front()==left) dq2.pop_front();
                left++;
            }
            // Any valid parition that ends at left-1, left, left+1, ..., i-1 is good.

            dp[i] = presum[i-1] - (left>=2?presum[left-2]:0);
            presum[i] = presum[i-1] + dp[i];

            dp[i] = (dp[i] + M) % M;
            presum[i] = (presum[i] + M) % M;            
        }

        return dp[n];        
    }
};
