class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n==0) return {};
        vector<int>dp(n,1);
        vector<int>prev(n,-1);

        for (int i=0; i<n; i++)
            for (int j=0; j<i; j++)
            {                
                if (nums[i]%nums[j]==0)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    if (dp[i]==dp[j]+1)
                        prev[i] = j;
                }                    
            }
        
        int len = 0, idx;
        for (int i=0; i<n; i++)
        {
            if (dp[i]>len)
            {
                len = dp[i];
                idx = i;
            }
        }

        vector<int>ret;
        while (idx!=-1)
        {
            ret.push_back(nums[idx]);
            idx = prev[idx];
        }
        return ret;
    }
};
