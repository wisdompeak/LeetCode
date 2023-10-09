class Solution {        
public:
    int minOperations(string s1, string s2, int x) 
    {
        int ret = 0;
     
        vector<int>nums;
        for (int i=0; i<s1.size(); i++)
            if (s1[i]!=s2[i])
                nums.push_back(i);
        
        int n = nums.size();
        if (n==0) return 0;
        if (n%2!=0) return -1;
        
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX/2));
        for (int i=0; i+1<n; i++)
            dp[i][i+1] = min(x, nums[i+1]-nums[i]);
        
        for (int d=4; d<=n; d+=2)
        {
            for (int i=0; i+d-1<n; i++)
            {
                int j = i+d-1;
                
                dp[i][j] = dp[i+1][j-1] + min(x, nums[j]-nums[i]);
                
                for (int k=i+1; k+1<j; k+=2)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
            }
        }
        
        return dp[0][n-1];        
    }
};
