class Solution {
    bool dp[5001][5001];
    bool table[256][256];
    unordered_map<char, unordered_set<char>>Map;
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        int m = s.size();
        int n = sub.size();
        s = "#"+s;
        sub = "#"+sub;
        
        for (auto x: mappings)
        {
            table[x[0]][x[1]] = 1;
        }
        
        for (int i=0; i<=m; i++)
            dp[i][0] = true;
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (dp[i-1][j-1]==0) continue;
                
                if (s[i]==sub[j] || table[sub[j]][s[i]])
                    dp[i][j] = dp[i-1][j-1];
                
                if (j==n && dp[i][j]==true)
                    return true;
            }
        return false;
        
    }
};
