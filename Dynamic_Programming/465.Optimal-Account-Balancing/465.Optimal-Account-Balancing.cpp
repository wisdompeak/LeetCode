class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) 
    {
        unordered_map<int,int>balance;
        for (auto& t: transactions)
        {
            balance[t[0]]+=t[2];
            balance[t[1]]-=t[2];
        }
        vector<int>nums;
        for (auto x: balance)
            nums.push_back(x.second);

        int n = nums.size();        
        vector<int>sum(1<<n, 0);
        for (int state = 0; state < (1<<n); state++)
        {            
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)
                    sum[state] += nums[i];
            }             
        }

        vector<int>dp(1<<n, INT_MAX/2);
        for (int state = 0; state < (1<<n); state++)
        {
            if (sum[state] != 0)  continue;
            dp[state] = __builtin_popcount(state)-1;
            for (int subset=state-1; subset>0; subset=(subset-1)&state)
            {
                if (sum[subset]==0)
                {
                    dp[state] = min(dp[state], dp[subset]+dp[state-subset]);
                }
                    
            }
        }
        return dp[(1<<n)-1];
    }
};
