using LL = long long;
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) 
    {
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<queries.size(); i++)
            Map[queries[i][1]^queries[i][0]].push_back(i);
        
        
        int m = queries.size();
        vector<vector<int>>rets(m);
        for (int i=0; i<m; i++)
            rets[i] = {-1, -1};
        
        int n = s.size();
        for (int len=1; len<=31; len++)
        {
            LL sum = 0;
            for (int i=0; i<n; i++)
            {
                sum = sum*2+(s[i]-'0');
                if (i>=len)
                    sum -= (1LL<<len)*(s[i-len]-'0');
                
                if (Map.find(sum)!=Map.end())
                {
                    for (int idx: Map[sum])
                    {
                        if (rets[idx][0]!=-1)
                            break;
                        rets[idx] = {i-len+1, i};
                    }                        
                }
            }
        }
        
        return rets;
        
    }
};
