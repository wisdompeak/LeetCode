class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) 
    {
        int M = s.size();
        int N = p.size();
        s = "0"+s;
        p = "0"+p;
        auto dp = vector<vector<int>>(M+1,vector<int>(N+1,0));
        dp[0][0] = 1;
        for (int j=2; j<=N; j++)
        {
            if (p[j]=='*') dp[0][j]=dp[0][j-2];
        }
        
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                if (isalpha(p[j]))
                {
                    dp[i][j] = (s[i]==p[j] && dp[i-1][j-1]);
                }
                else if (p[j]=='.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');
                    dp[i][j] = temp1 || temp2;
                }
                
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        return dp[M][N];
    }
};
