class Solution {
public:
    int numDecodings(string s) 
    {
        s.insert(s.begin(),'0');
        int N=s.size();
        vector<int>dp(s.size(),0);
        
        if (N==1) return 0;
        
        dp[0]=1;
        
        if (s[1]=='0') 
            dp[1]=0;
        else
            dp[1]=1;
        if (N==1) return dp[1];
                
        for (int i=2; i<s.size(); i++)
        {
            int part1, part2;
            
            if (s[i]=='0')
                part1 = 0;
            else
                part1 = dp[i-1];
                
            int num = stoi(s.substr(i-1,2));
            if (num>=10 && num<=26)
                part2 = dp[i-2];
            else
                part2 = 0;
                
            dp[i] = part1+part2;
        }
        
        return dp.back();
        
    }
};
