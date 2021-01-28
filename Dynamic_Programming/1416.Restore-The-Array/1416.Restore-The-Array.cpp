class Solution {
    int dp[100001];
    long long M = 1e9+7;
public:
    int numberOfArrays(string s, int k) 
    {
        int n = s.size();
        s = "#"+s;        
        dp[0] = 1;
        
        for (int i=1; i<=n; i++)
        {
            long long x = 0;
            for (int j=0; j<10; j++)
            {
                if (i-j<=0) break;
                x = x + pow(10,j)*(s[i-j]-'0');
                if (x>k) break;
                if (x==0) continue;
                if (j>0 && s[i-j]=='0') continue;                
                dp[i] = (dp[i]+dp[i-j-1]) % M;                
            }
        }
        return dp[n];        
    }
};
