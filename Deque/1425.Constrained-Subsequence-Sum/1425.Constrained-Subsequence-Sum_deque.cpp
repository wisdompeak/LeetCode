class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>dp(n,0);
        deque<int>q;
        
        int ret = INT_MIN;
        for (int i=0; i<n; i++)
        {
            while (q.size()>0 && q.front() < i-k)
                q.pop_front();
            
            dp[i] = nums[i];
            if (q.size()>0) dp[i] = max(dp[i], dp[q.front()] + nums[i]);            
            
            while (q.size()>0 && dp[q.back()] <= dp[i])
                q.pop_back();
            q.push_back(i);
        }
                
        for (int i=0; i<n; i++)
            ret = max(ret, dp[i]);
        return ret;
        
    }
};
