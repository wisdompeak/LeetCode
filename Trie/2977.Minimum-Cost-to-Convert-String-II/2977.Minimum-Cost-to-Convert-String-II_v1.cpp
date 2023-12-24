using LL = long long;
class Solution {    
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) 
    {
        unordered_set<string>Set;
        Set.insert(original.begin(), original.end());
        Set.insert(changed.begin(), changed.end());
        unordered_map<string, int>Map;
        int idx = 0;
        for (string x: Set)
        {
            Map[x] = idx;
            idx++;
        }
        
        int n = Set.size();
        LL d[n][n];
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                if (i==j)
                    d[i][j] = 0;
                else
                    d[i][j] = LLONG_MAX/2;
            }
        
        for (int i=0; i<original.size(); i++)
            d[Map[original[i]]][Map[changed[i]]] = min(d[Map[original[i]]][Map[changed[i]]], (LL)cost[i]);
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        
        
        int m = source.size();
        source = "#"+source;
        target = "#"+target;
        
        vector<LL>dp(m+1);
        dp[0] = 0;
        
        for (int i=1; i<=m; i++)
        {
            dp[i] = LLONG_MAX/2;
            if (source[i]==target[i])
                dp[i] = dp[i-1];            
            
            string a;
            string b;
            for (int j=i; j>=1; j--)
            {
                a = source.substr(j,1) + a;
                b = target.substr(j,1) + b;
                
                if (Map.find(a)!=Map.end() && Map.find(b)!=Map.end())
                    dp[i] = min(dp[i], dp[j-1] + d[Map[a]][Map[b]]);
            }
        }
        
        if (dp[m]==LLONG_MAX/2) return -1;
        
        return dp[m];
    }
};
