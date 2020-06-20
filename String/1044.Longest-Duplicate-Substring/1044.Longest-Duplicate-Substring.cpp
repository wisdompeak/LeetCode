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
        unordered_set<long long>Set;
        long long base = 26;
        long long mod = (1l<<32);
        long long hash = 0;

        long long pow_base_len = 1;
        for (int i=0; i<len; i++)        
            pow_base_len = (pow_base_len * base) % mod;                    
            
        for (int i=0; i<S.size(); i++)
        {
            hash = (hash * base + (S[i]-'a')) % mod;
            if (i>=len)            
                hash = (hash - pow_base_len*(S[i-len]-'a') ) % mod;                            

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
