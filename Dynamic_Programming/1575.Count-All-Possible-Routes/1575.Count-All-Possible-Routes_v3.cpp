class Solution {
    long dp[201][101][3];
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        int n = locations.size();        
        int startPos = locations[start], finishPos = locations[finish];
        sort(locations.begin(),locations.end());
        
        int startIdx, finishIdx;
        for (int i=0; i<n; i++)
        {
            if (locations[i]==startPos) startIdx = i;
            if (locations[i]==finishPos) finishIdx = i;
        }
        dp[fuel][startIdx][0] = 1;
        long M = 1e9+7;
        
        for (int f=fuel; f>=0; f--)
            for (int c=0; c<n; c++)
            {
                if (c>0 && f+locations[c]-locations[c-1] <= fuel)
                {
                    int gas = locations[c]-locations[c-1];                    
                    dp[f][c][0] += dp[f+gas][c-1][0] + dp[f+gas][c-1][2];
                    dp[f][c][2] += dp[f+gas][c-1][0] + dp[f+gas][c-1][2];
                }
                if (c<n-1 && f+locations[c+1]-locations[c] <= fuel)
                {
                    int gas = locations[c+1]-locations[c]; 
                    dp[f][c][0] += dp[f+gas][c+1][0] + dp[f+gas][c+1][1];
                    dp[f][c][1] += dp[f+gas][c+1][0] + dp[f+gas][c+1][1];
                }
                dp[f][c][0]%=M;
                dp[f][c][1]%=M;
                dp[f][c][2]%=M;
            }
        long ret = 0;
        for (int f=0; f<=fuel; f++)
            ret = (ret+dp[f][finishIdx][0])%M;
        return ret;
    }
};
