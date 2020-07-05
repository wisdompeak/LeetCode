class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int K = k;
        int m = nums1.size();
        int n = nums2.size();
        nums1.insert(nums1.begin(), 0);
        nums2.insert(nums2.begin(), 0);

        string dp[m+1][n+1][K+1];        

        for (int i=0; i<=m; i++)
            for (int j=0; j<=n; j++)
                for (int k=1; k<=min(K,i+j); k++)
                {
                    dp[i][j][k] = "";
                    if (i-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+to_string(nums1[i]));
                    if (j-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+to_string(nums2[j]));
                    if (i-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                    if (j-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);                    
                }

        vector<int>ret;
        for (int i=0; i<dp[m][n][K].size(); i++)
            ret.push_back(dp[m][n][K][i]-'0');

        return ret;
    }
