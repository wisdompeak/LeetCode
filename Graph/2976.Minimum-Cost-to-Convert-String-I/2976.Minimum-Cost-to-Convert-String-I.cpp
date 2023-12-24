using LL = long long;   
class Solution {
    LL d[26][26];    
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        for (int i=0; i<26; i++)
            for (int j=0; j<26; j++)
            {
                if (i!=j)
                    d[i][j] = LLONG_MAX/3;
                else
                    d[i][j] = 0;
            }
                
        
        for (int i=0; i<cost.size(); i++)            
            d[original[i]-'a'][changed[i]-'a'] = min(d[original[i]-'a'][changed[i]-'a'], (LL)cost[i]);
        
        for (int k=0; k<26; k++)
            for (int i=0; i<26; i++)
                for (int j=0; j<26; j++)
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        
        LL ret = 0;
        for (int i=0; i<source.size(); i++)
        {
            int a = source[i]-'a';
            int b = target[i]-'a';
            if (d[a][b]==LLONG_MAX/3) return -1;
            ret += d[a][b];
        }
        
        return ret;
    }
};
