class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        int n = arr.size();
        auto dp = vector<vector<int>>(n, vector<int>(2));
        
        dp[0][0] = arr[0];
        dp[0][1] = 0;    
        
        int ret = arr[0];
        for (int i=1; i<n; i++)
        {
            dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
            ret = max(ret, max(dp[i][0], dp[i][1]));    
        }
        return ret;
    }
};


// Kadane
// dp[i][0] :  maximum sum for a non-empty subarray ending at i, w/o any deletion.
// dp[i][1] :  maximum sum for a non-empty subarray ending at i, w/ one deletion.    



    




