using LL = long long;
class Solution {
    LL dp1[10005][10][10];
    LL dp2[10005][10][10];
    LL count1[10005][10];
    LL count2[10005][10];
    LL M = 1e9+7;
public:
    int countPalindromes(string s) 
    {
        int n = s.size();
        s = "#"+s;
        
        for (int j=0; j<=9; j++)
        {
            int sum = 0;
            for (int i=1; i<=n; i++)
            {
                sum += (s[i]-'0'==j);
                count1[i][j] = sum;
            }
        }
        
        for (int j=0; j<=9; j++)
        {
            int sum = 0;
            for (int i=n; i>=1; i--)
            {
                sum += (s[i]-'0'==j);
                count2[i][j] = sum;
            }
        }        
        
        for (int i=2; i<=n; i++)            
            for (int j=0; j<=9; j++)            
                for (int k=0; k<=9; k++)
                {
                    dp1[i][j][k] = dp1[i-1][j][k];                    
                    if (s[i]=='0'+k)                    
                        dp1[i][j][k] = (dp1[i][j][k] + count1[i-1][j]) % M;
                }       
        
        for (int i=n-1; i>=1; i--)
            for (int j=0; j<=9; j++)            
                for (int k=0; k<=9; k++)         
                {
                    dp2[i][j][k] = dp2[i+1][j][k];
                    if (s[i]=='0'+k)                    
                        dp2[i][j][k] = (dp2[i][j][k] + count2[i+1][j]) % M;                    
                }
        
        LL ret = 0;
        for (int i=3; i<=n-2; i++)
            for (int j=0; j<=9; j++)
                for (int k=0; k<=9; k++)
                {
                    ret += dp1[i-1][j][k] * dp2[i+1][j][k] % M;
                    ret %= M;
                }
        return ret;
    }
};
