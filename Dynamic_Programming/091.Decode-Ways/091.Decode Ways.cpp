class Solution {
public:
    int numDecodings(string s) 
    {
        if (s.size()==0) return 0;
        
        int N =s.size();
        s = "#"+s;
        vector<int>dp(N+1,0);
        
        dp[0] = 1;
        dp[1] = s[1]=='0'? 0:1;
        
        for (int i=2; i<=N; i++)
        {
            // Check if s[i] alone can stand for a letter
            if (s[i]!='0')
            {
                dp[i] += dp[i-1];
            }
            
            // Check if s[i-1:i] can stand for a letter
            if (s[i]>='0' && s[i]<='6' && (s[i-1]=='1'||s[i-1]=='2'))
                dp[i]+=dp[i-2];
            else if (s[i]>='7' && s[i]<='9' && s[i-1]=='1')
                dp[i]+=dp[i-2];
            
            // cout<<i<<" "<<dp[i]<<endl;
        }
        
        return dp[N];
        
    }
};

