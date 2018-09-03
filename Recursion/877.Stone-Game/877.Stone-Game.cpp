class Solution {
public:
    bool stoneGame(vector<int>& nums) 
    {
        if(nums.size()% 2 == 0) return true;
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int myBest = utill(nums, dp, 0, n-1);
        return 2*myBest >= accumulate(nums.begin(), nums.end(), 0)?1:2;
    }
    
    int utill(vector<int>& v, vector<vector<int>> &dp, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = v[i] + min(utill(v,dp, i+1, j-1), utill(v, dp, i+2, j));
        int b = v[j] + min(utill(v,dp,i, j-2), utill(v,dp, i+1, j-1));
        dp[i][j] = max(a, b);
                        
        return dp[i][j];
    }
};
