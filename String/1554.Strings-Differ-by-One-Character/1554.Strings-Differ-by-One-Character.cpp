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
            for (auto ch: dict[i])            
                h = h * base + (ch-'a');
            hash[i] = h;
        }
        
        ULL power = 1;
        for (int j=m-1; j>=0; j--)
        {                        
            unordered_set<ULL>Set;
            for (int i=0; i<n; i++)
            {
                ULL hash_new = hash[i] - (dict[i][j]-'a')*power;
                if (Set.find(hash_new)!=Set.end())
                    return true;
                Set.insert(hash_new);
            }            
            
            power *= base;
        }
        
        return false;
    }
};
