typedef uint64_t ULL;
class Solution {
    unordered_map<int,int>len2start;
public:
    string longestDupSubstring(string S) 
    {
        int left = 1, right = S.size()-1;
        while (left<right)
        {
            int mid = right - (right-left)/2;
            if (found(S,mid))
                left = mid;
            else
                right = mid - 1;
        }
        if (found(S, left))
            return S.substr(len2start[left],left);
        else
            return "";        
    }

    bool found(string&S, int len)
    {
        unordered_set<ULL>Set;
        ULL base = 31;
        ULL hash = 0;

        ULL pow_base_len = 1;
        for (int i=0; i<len; i++)        
            pow_base_len = pow_base_len * base;                    
            
        for (int i=0; i<S.size(); i++)
        {
            hash = hash * base + (S[i]-'a');                                     
            
            if (i>=len)            
                hash = (hash - pow_base_len*(S[i-len]-'a') ) ;               

            if (i>=len-1)
            {                
                if (Set.find(hash)!=Set.end())
                {
                    len2start[len] = i-len+1;
                    return true;
                }                
                Set.insert(hash);
            }          
        }
        return false;
    }
};
