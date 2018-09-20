class Solution {
    int dp[10001]={0};
public:
    int racecar(int target) 
    {
        if (dp[target]!=0) return dp[target];
        
        int n = log2(target+1);
        if (pow(2,n)-1==target)
        {
            dp[target] = n;
            return n;   
        }
        
        // run past the taget
        dp[target] = (n+1)+1+racecar(pow(2,n+1)-1-target);
        
        // stop before the target
        for (int k = 0; k<n; k++)
        {
            int temp = n+1+k+1+ racecar( target - (pow(2,n)-1) + (pow(2,k)-1) );
            dp[target] = min(dp[target],temp);
        }
        
        return dp[target];
    }
};
