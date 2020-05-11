class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        multiset<int>Set;
        vector<int>dp(n,0);
        
        int ret = INT_MIN;
        
        for (int i=0; i<n; i++)
        {
            if (Set.size()>k && i-k-1>=0)
                Set.erase(Set.lower_bound(dp[i-k-1]));
            
            dp[i] = nums[i];
            if (Set.size()>0) dp[i] = max(dp[i], *Set.rbegin()+nums[i]);
            ret = max(ret, dp[i]);
            
            Set.insert(dp[i]);            
        }
        
        return ret;
        
    }
};
