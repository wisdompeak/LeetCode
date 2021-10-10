class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int mn = INT_MAX;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                mn = min(mn, grid[i][j]);
        
        vector<int>nums;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if ((grid[i][j]-mn)%x!=0)
                    return -1;
                nums.push_back(grid[i][j]);
            }
        
        sort(nums.begin(), nums.end());
        int k = nums.size();
        int ret = 0;
        for (auto t: nums)
        {
            ret += abs(nums[(k-1)/2]-t)/x;
        }
        return ret;
    }
};
