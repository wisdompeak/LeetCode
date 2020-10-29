class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        nums1.insert(nums1.begin(),0);
        nums2.insert(nums2.begin(),0);
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,INT_MIN/2));
                
        int ret = INT_MIN;
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                dp[i][j] = max(dp[i][j], max(0, dp[i-1][j-1])+nums1[i]*nums2[j]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
               
                ret = max(ret, dp[i][j]);
            }
        
        return ret;        
    }
};
