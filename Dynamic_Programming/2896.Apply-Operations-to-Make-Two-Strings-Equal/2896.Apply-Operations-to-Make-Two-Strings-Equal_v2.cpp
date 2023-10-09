class Solution {        
public:
    int minOperations(string s1, string s2, int x) 
    {
        int ret = 0;
        
        vector<int>nums;
        for (int i=0; i<s1.size(); i++)
            if (s1[i]!=s2[i])
                nums.push_back(i);                
        if (nums.size()==0) return 0;
        if (nums.size()%2!=0) return -1;
        
        int n = nums.size();
        
        nums.insert(nums.begin(), 0);
                
        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;
        
        for (int i=1; i<=n; i++)
            for (int j=0; j<=1; j++)
            {   
                if (i-2>=0)
                    dp[i][j] = min(dp[i][j], dp[i-2][j] + (nums[i]-nums[i-1]));                
                
                if (j-1>=0 && j-1<=i-1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + x);                
                
                if (j+1<=i-1)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]);                                
            }
        
        
        return dp[n][0];        
    }
};
