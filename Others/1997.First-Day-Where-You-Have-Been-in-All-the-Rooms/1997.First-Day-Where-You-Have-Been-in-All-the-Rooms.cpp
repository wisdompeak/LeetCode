class Solution {
    long dp[100000];    
    long M = 1e9+7;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) 
    {
        n = nextVisit.size();
        dp[0] = 0;
        for (int i=0; i<n-1; i++)
        {
            int prev = nextVisit[i];            
            dp[i+1] = dp[i] + 1 + (dp[i]-dp[prev] + M ) % M + 1;            
            dp[i+1] %= M;
        }
        return dp[n-1];        
    }
};
