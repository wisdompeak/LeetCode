class Solution {    
public:
    int dp[10001]={0};
    int racecar(int target) 
    {
        if (dp[target]!=0)
            return dp[target];                
        
        int n = log2(target+1);
        
        if ((1<<n)-1==target)
        {
            dp[target]=n;
            return dp[target];
        }
                
        dp[target] = (n+1)+1+racecar((1<<(n+1))-1-target);
        for (int m=0; m<n; m++)
        {
            dp[target] = min(dp[target], racecar(target-((1<<n)-1)+((1<<m)-1))+n+1+m+1);            
        }
        return dp[target];
        
    }
};
