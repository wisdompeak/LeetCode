class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        int n = s.size();
        vector<int>dp(26, 0); 
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int temp = 0;
            for (int ch = max(0, s[i]-'a'-k); ch <= min(25, s[i]-'a'+k); ch++)            
                temp = max(temp, dp[ch]+1);            
            
            dp[s[i]-'a'] = temp;            
            ret = max(ret, temp);
        }
        
        return ret;
    }
};
