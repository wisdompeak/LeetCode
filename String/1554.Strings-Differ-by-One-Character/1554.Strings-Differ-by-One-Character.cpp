typedef uint64_t ULL;
class Solution {
public:
    bool differByOne(vector<string>& dict) 
    {
        ULL base = 26;        
        int n = dict.size();
        int m = dict[0].size();
        vector<ULL>hash(n);
        for (int i=0; i<n; i++)
        {
            ULL h = 0;
            for (int j=0; j<m; j++)
                h = h*base+dict[i][j]-'a';
            hash[i] = h;
        }
        
        ULL del = 1;
        for (int j=m-1; j>=0; j--)
        {
            unordered_set<ULL>Set;            
            
            for (int i=0; i<n; i++)
            {
                ULL h = hash[i]  - (dict[i][j]-'a') * del;
                if (Set.find(h)!=Set.end())
                    return true;
                Set.insert(h);
            }
            del = del*base;
        }
        
        return false;
    }
};
