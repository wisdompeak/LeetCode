class Solution {
public:
    int longestRepeatingSubstring(string S) 
    {
        int left = 1, right = S.size()-1;
        while (left<right)
        {
            int mid = right-(right-left)/2;
            if (found(S, mid))
                left = mid;
            else
                right = mid-1;
        }
        if (found(S, left)) return left;
        else return 0;
    }
    
    bool found(string& S, int len)
    {
        long base = 26;
        long mod = 1e9+7;
        long hash = 0;
        long pow_base_len = 1;
        unordered_set<long>Set;
        for (int i=0; i<len; i++)
            pow_base_len = pow_base_len*base % mod;
        
        for (int i=0; i<S.size(); i++)
        {
            hash = (hash*base+S[i]-'a') % mod;
            if (i>=len)
                hash = (hash - pow_base_len*(S[i-len]-'a')%mod + mod)%mod;
            
            if (i>=len-1)
            {
                if (Set.find(hash)!=Set.end())
                    return true;
                Set.insert(hash);
            }
        }
        return false;
            
    }
};
