class Solution {
public:
    int distinctEchoSubstrings(string text) 
    {
        int n = text.size();
        text = "#"+text;
        auto dp = vector<vector<int>>(n+1, vector<int>(n+1,0));
        dp[0][0] = 0;
        unordered_set<string>Set;
        int count = 0;
        
        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
            {
                if (text[i]==text[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                if (dp[i][j] >= j-i )
                {
                    string str = text.substr(i+1, j-i);
                    if (Set.find(str)==Set.end())
                    {
                        count++;
                        Set.insert(str);
                    }
                }                
            }
        return count;
    }
};
