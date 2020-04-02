class Solution {
public:
    bool isValidPalindrome(string s, int k) 
    {
        int m = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        
        s = "#"+s;
        t = "#"+t;
                
        auto dp = vector<vector<int>>(m+1,vector<int>(m+1,0));
        
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= m; j++) 
            {             
                if (s[i] == t[j]) 
                    dp[i][j] = dp[i - 1][j - 1]+1; 
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }         
  
        return m-dp[m][m]<=k; 
    }
};
