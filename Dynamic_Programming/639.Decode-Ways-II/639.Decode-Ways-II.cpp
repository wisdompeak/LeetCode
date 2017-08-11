class Solution {
public:
    int numDecodings(string s) 
    {
        int M=pow(10,9)+7;
        
        s.insert(s.begin(),' ');
        int N=s.size();
        vector<long long>dp(N,0);        
        
        if (N-1==0) return 0;
        
        if (s[1]=='0') dp[1]=0;
        if (s[1]=='*') dp[1]=9;
        if (s[1]>='1' && s[1]<='9') dp[1]=1;
        if (N-1==1) return dp[1];
        
        dp[0]=1;        
        
        for (int i=2; i<s.size(); i++)
        {
            if (s[i]=='0')
            {
                if (s[i-1]=='*')
                    dp[i]=dp[i-2]*2;
                else if (s[i-1]!='1' && s[i-1]!='2')
                    return 0;
                else
                    dp[i]=dp[i-2];
            }
            else if (s[i]>='1' && s[i]<='6')
            {
                if (s[i-1]=='*')
                    dp[i]=dp[i-2]*2+dp[i-1]*1;
                else
                {
                    int num=stoi(s.substr(i-1,2));
                    if (num>=11 && num<=26)
                        dp[i]=dp[i-2]+dp[i-1];
                    else
                        dp[i]=dp[i-1];
                }
            }
            else if (s[i]>='7' && s[i]<='9')
            {
                if (s[i-1]=='*')
                    dp[i]=dp[i-2]*1+dp[i-1];
                else
                {
                    int num=stoi(s.substr(i-1,2));
                    if (num>=11 && num<=26)
                        dp[i]=dp[i-2]+dp[i-1];
                    else
                        dp[i]=dp[i-1];
                }
            }            
            else if (s[i]=='*')
            {
                if (s[i-1]=='*')
                    dp[i]=dp[i-2]*15+dp[i-1]*9;
                else if (s[i-1]=='0')
                    dp[i]=dp[i-1]*9;
                else if (s[i-1]=='1')
                    dp[i]=dp[i-2]*9+dp[i-1]*9;
                else if (s[i-1]=='2')
                    dp[i]=dp[i-2]*6+dp[i-1]*9;
                else
                    dp[i]=dp[i-1]*9;
            }
            
            dp[i]=dp[i]%M;
        }
        
        return dp[N-1];
    }
};
