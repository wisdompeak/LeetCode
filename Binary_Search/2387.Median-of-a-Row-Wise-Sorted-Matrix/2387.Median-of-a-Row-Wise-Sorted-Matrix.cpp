class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();        
        int k = (m*n+1)/2;
        
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            int count = 0;
            for (int i=0; i<m; i++)
                count += upper_bound(grid[i].begin(), grid[i].end(), mid) - grid[i].begin();
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
        
    }
};
