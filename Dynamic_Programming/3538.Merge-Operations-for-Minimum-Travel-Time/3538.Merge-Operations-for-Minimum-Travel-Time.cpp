const int INF = INT_MAX / 2;
int dp[51][11][101];

class Solution {    
public:
    int minTravelTime(int l, int n, int K, vector<int>& pos, vector<int>& time) {
        
        fill(&dp[0][0][0], &dp[0][0][0]+51*11*101, INT_MAX/2);
        
        dp[0][0][time[0]] = 0;

        for (int i=0; i<n; i++)
            for (int m=0; m<=K; m++)
                for (int v=0; v<=100; v++)
                {
                    int t = 0;                                        
                    for (int j=i+1; j<n && m+j-i-1<=K; j++)
                    {
                        t += time[j];
                        dp[j][m+j-i-1][t] = min(dp[j][m+j-i-1][t], dp[i][m][v] + v*(pos[j]-pos[i])); 
                    } 
                }

        int ans = INT_MAX/2;
        for (int v = 0; v <= 100; v++) {
            ans = min(ans, dp[n - 1][K][v]);
        }
        return ans;
    }
};
