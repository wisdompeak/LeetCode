typedef uint64_t ULL;
class Solution {
public:
    int countDistinct(string s) 
    {
        int n = s.size();
        ULL base = 26;
        int count = 0;
        
        for (int len = 1; len <=n; len++)
        {            
            ULL power = 1;
            for (int i=0; i<len-1; i++)
                power *= base;
            
            unordered_set<ULL>Set;
            ULL hash = 0;            
            for (int i=0; i<n; i++)
            {                
                if (i-len>=0)
                    hash = hash - (s[i-len]-'a')*power;
                hash = hash * base + (s[i]-'a');
                if (i>=len-1)
                    Set.insert(hash);
            }
            count += Set.size();
        }
        return count;        
    }
};
