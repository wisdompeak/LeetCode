class Solution {
    string dp[150][150];
public:
    string encode(string s) 
    {
        int n = s.size();
        for (int i=0; i<n; i++)
            dp[i][i] = s.substr(i,1);
                               
        for (int len = 2; len <=n; len++)
            for (int i=0; i+len-1<n; i++)
            {
                int j = i+len-1;
                dp[i][j] = help(s, i, j);
                for (int k=i; k<j; k++)
                {
                    if (dp[i][k].size() + dp[k+1][j].size() < dp[i][j].size())
                        dp[i][j] = dp[i][k]+dp[k+1][j];
                }
            }
        return dp[0][n-1];        
    }
    
    string help(string& str, int a, int b)
    {
        string s = str.substr(a, b-a+1);
        string ret = s;
        for (int len=1; len<s.size(); len++)
        {
            if (s.size()%len!=0) continue;
            int flag = 1;
            for (int i=len; i<s.size(); i+=len)
            {
                if (s.substr(i, len)!=s.substr(0, len))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                string t = to_string(s.size()/len)+"["+dp[a][a+len-1]+"]";
                if (t.size() < ret.size())
                    ret = t;
            }
        }
        return ret;
    }    
};
