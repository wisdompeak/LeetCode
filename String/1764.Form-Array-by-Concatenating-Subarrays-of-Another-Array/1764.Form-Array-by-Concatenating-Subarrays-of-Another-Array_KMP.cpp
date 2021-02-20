class Solution {
    int dp[1000];

public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) 
    {
        vector<vector<int>>lsps = preprocess(groups);
        int cur = 0;
        for (int i=0; i<groups.size(); i++)
        {
            if (cur>=nums.size()) return false;
            cur = find(nums, cur, groups[i], lsps[i]);            
            if (cur == -1) return false;
            cur += groups[i].size();            
        }
        return true;
    }

    int find(vector<int>&nums, int cur, vector<int>&p, vector<int>&lsp)
    {
        int n = nums.size();
        dp[cur] = (p[0]==nums[cur]);
        if (lsp.size()==1 && dp[cur]==1)
            return cur;
        for (int i=cur+1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && p[j]!=nums[i])
                j = lsp[j-1];
            dp[i] = j + (p[j]==nums[i]);
            if (dp[i] == p.size())
                return i-p.size()+1;
        }
        return -1;
    }

    vector<vector<int>> preprocess(vector<vector<int>>& groups)
    {
        vector<vector<int>> rets;
        for (auto &g: groups)
        {
            int n = g.size();
            vector<int>dp(n);
            dp[0] = 0;
            for (int i=1; i<n; i++)
            {
                int j = dp[i-1];
                while (j>0 && g[j]!=g[i])
                    j = dp[j-1];
                dp[i] = j + (g[j]==g[i]);
            }
            rets.push_back(dp);
        }
        return rets;
    }

};
