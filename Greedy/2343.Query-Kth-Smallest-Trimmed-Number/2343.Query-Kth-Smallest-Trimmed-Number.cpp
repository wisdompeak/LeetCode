class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>>ans(n+1, vector<int>(m));

        for (int i=0; i<m; i++)
            ans[0][i] = i;
        
        for (int t=1; t<=n; t++)
        {
            vector<vector<int>>bucket(10);
            for (int i=0; i<m; i++)
            {
                int idx = ans[t-1][i];                
                bucket[nums[idx][n-t]-'0'].push_back(idx);
            }
            
            int i = 0;
            for (int b=0; b<10; b++)            
                for (int idx: bucket[b])
                {
                    ans[t][i] = idx;
                    i++;
                }
        }

        vector<int>rets;
        for (auto& q: queries)
        {
            rets.push_back(ans[q[1]][q[0]-1]);
        }            

        return rets;
    }
};
