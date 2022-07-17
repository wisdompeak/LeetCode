class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int m = nums.size(), n = nums[0].size();
        vector<vector<int>>ans(n+1, vector<int>(m));
        
        for (int j=0; j<m; j++)
            ans[0][j] = j;
        
        for (int i=1; i<=n; i++)
        {
            vector<vector<int>>buckets(10);
            
            for (int j=0; j<m; j++)
            {
                int idx = ans[i-1][j];
                buckets[nums[idx][nums[idx].size()-i] - '0'].push_back(idx);
            }
            
            int j = 0;
            for (int b=0; b<=9; b++)
            {
                for (int idx: buckets[b])
                {
                    ans[i][j] = idx;
                    j++;
                }
            }
        }
        
        vector<int>rets;
        for (auto q: queries)
        {
            rets.push_back(ans[q[1]][q[0]-1]);
        }
        return rets;
    }
};
