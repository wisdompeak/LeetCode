class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        nums.insert(nums.begin(),0);
        vector<int>dp(n+1,0);
        multiset<int>Set({0});

        int ret = INT_MIN;
        for (int i=1; i<=n; i++)
        {
            if (Set.size()>k)            
                Set.erase(Set.lower_bound(dp[i-k-1]));            

            dp[i] = max(nums[i], *Set.rbegin()+nums[i]);
            ret = max(ret, dp[i]);
            Set.insert(dp[i]);
        }

        return ret;
    }
};
