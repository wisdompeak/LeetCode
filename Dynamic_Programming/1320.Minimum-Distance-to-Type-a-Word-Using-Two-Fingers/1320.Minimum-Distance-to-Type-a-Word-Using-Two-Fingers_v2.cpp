class Solution {
public:
    int minimumDistance(string word) 
    {            
        int n = word.size();
        auto dp = vector<vector<int>>(n,vector<int>(26,INT_MAX/2));
        
        for (int i=0; i<26; i++)        
            dp[0][i] = 0;
        
        for (int k=1; k<n; k++)
        {
            int cur = word[k]-'A';
            int prev = word[k-1]-'A';

            for (int i=0; i<26; i++)
            {
                dp[k][i] = min(dp[k][i], dp[k-1][i]+dis(prev,cur));                
                dp[k][i] = min(dp[k][i], dp[k-1][cur]+dis(prev,i));
            }
        }
                
        int ret = INT_MAX;
        for (int i=0; i<26; i++)
            ret = min(ret, dp[n-1][i]);
        return ret;
    }
    
    int dis(int a, int b)
    {
        if (a==26) return 0;
        int x1 = a/6;
        int y1 = a%6;
        int x2 = b/6;
        int y2 = b%6;
        return abs(x1-x2)+abs(y1-y2);
    }
};
