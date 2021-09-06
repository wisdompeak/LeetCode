class Solution {
    long dp[100000];    
    long M = 1e9+7;
    int n;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) 
    {
        n = nextVisit.size();
        dp[0] = 0;
        dp[1] = 2;
        long ret = 2;
        for (int i=1; i<n-1; i++)
        {
            int prev = nextVisit[i];            
            dp[i+1] = dp[i] + (dp[i]-dp[prev] + M +1) % M + 1;            
            dp[i+1] %= M;
        }
        return dp[n-1];        
    }
    
    
};
