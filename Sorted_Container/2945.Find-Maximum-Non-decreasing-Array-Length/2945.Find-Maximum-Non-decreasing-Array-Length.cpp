using LL = long long;
class Solution {
public:
    int findMaximumLength(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        
        vector<LL>dp(n+1,-1);
        vector<int>len(n+1,-1);
        vector<LL>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1] + nums[i];

        dp[0] = 0;
        len[0] = 0;
        int ret = 0;        
        map<LL,int>Map;
        Map[0] = 0;
        for (int i=1; i<=n; i++)
        {
            auto iter = Map.upper_bound(presum[i]);
            if (iter!=Map.begin())
            {
                int j = prev(iter)->second;
                len[i] = len[j]+1;
                dp[i] = presum[i] - presum[j];
            }

            while (!Map.empty() && Map.rbegin()->first >= presum[i]+dp[i])
                Map.erase(prev(Map.end()));
                            
            Map[presum[i]+dp[i]] = i;
        }

        return len[n];
        
    }
};
