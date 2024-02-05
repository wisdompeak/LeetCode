class Solution {
public:
    vector<int> longestPrefix(string s) 
    {
        int n = s.size();
        vector<int>dp(n);
        dp[0] = 0;

        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];                       
            while (j>=1 && s[j]!=s[i])
            {
                j = dp[j-1];
            }          
            dp[i] = j + (s[j]==s[i]);
        }

        return dp;        
    }
    
    int minimumTimeToInitialState(string word, int k) 
    {
        int n = word.size();
        vector<int>lcp = longestPrefix (word);
        int len = lcp[n-1];
        while (len!=0 && (n-len)%k!=0)        
            len = lcp[len-1];
        
        if (len!=0)
            return (n-len)/k;
        else
            return (n%k==0)?(n/k):(n/k+1);                      
    }
};
