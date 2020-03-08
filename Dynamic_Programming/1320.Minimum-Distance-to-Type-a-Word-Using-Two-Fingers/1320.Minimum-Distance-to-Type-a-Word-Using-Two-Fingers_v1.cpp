class Solution {
public:
    int minimumDistance(string word) 
    {        
        auto dp = vector<vector<vector<int>>>(301, vector<vector<int>>(26,vector<int>(26,INT_MAX/2)));
        int n = word.size();
        
        for (int i=0; i<26; i++)
        {
            dp[0][i][word[0]-'A'] = 0;
            dp[0][word[0]-'A'][i] = 0;
        }
        
        for (int k=1; k<word.size(); k++)
        {
            int ch = word[k]-'A';            
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++)
                {
                    dp[k][i][ch] = min(dp[k][i][ch], dp[k-1][i][j]+dis(j,ch));
                    dp[k][ch][j] = min(dp[k][ch][j], dp[k-1][i][j]+dis(i,ch));                    
                }
        }
        
        int ret = INT_MAX;
        for (int i=0; i<26; i++)
        {
            ret = min(ret, dp[n-1][i][word.back()-'A']);
            ret = min(ret, dp[n-1][word.back()-'A'][i]);
        }
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
