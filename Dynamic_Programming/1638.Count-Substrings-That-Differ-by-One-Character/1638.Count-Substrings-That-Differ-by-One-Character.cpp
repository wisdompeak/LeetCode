class Solution {
    int dp1[102][102];
    int dp2[102][102];
public:
    int countSubstrings(string s, string t) 
    {
        int m = s.size(); 
        int n = t.size();
        s = "#"+s+"#";
        t = "#"+t+"#";
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (s[i]==t[j])
                    dp1[i][j] = dp1[i-1][j-1]+1;
                else
                    dp1[i][j] = 0;                
            }
        
        cout<<"OK"<<endl;
        for (int i=m; i>=1; i--)
            for (int j=n; j>=1; j--)
            {
                if (s[i]==t[j])
                    dp2[i][j] = dp2[i+1][j+1]+1;
                else
                    dp2[i][j] = 0;
            }
        
        int ret = 0;
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (s[i]!=t[j])
                    ret += (dp1[i-1][j-1]+1)*(dp2[i+1][j+1]+1);
            }
        return ret;
    }
};
