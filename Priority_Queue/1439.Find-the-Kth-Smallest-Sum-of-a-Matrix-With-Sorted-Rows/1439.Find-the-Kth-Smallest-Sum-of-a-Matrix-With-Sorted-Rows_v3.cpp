class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int target = left+(right-left)/2;
            if (checkOK(mat, target, k))  // If the # of arrays whose sum <= target is at least k
                right = target;
            else
                left = target+1;
        }
        return left;        
    }
    
    // Check if the # of arrays whose sum <= target is at least k
    // o(K)
    bool checkOK(vector<vector<int>>& mat, int target, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        int sum = 0;
        for (int i=0; i<m; i++)
            sum += mat[i][0];
        int count = 1;
        
        if (sum > target) return false;
        
        dfs(mat, 0, sum, count, target, k);
        
        return count>=k;        
    }
    
    void dfs(vector<vector<int>>& mat, int row, int sum, int& count, int target, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        if (count >= k) return;
        if (row==m) return;
        
        for (int j=0; j<n; j++)
        {
            if (sum + mat[row][j] - mat[row][0] <= target)
            {
                if (j>0) count++;
                dfs(mat, row+1, sum + mat[row][j] - mat[row][0], count, target, k);
            }
            else
                break;
        }
    }    
};

