class Solution {
public:
    int countDistinct(string s) 
    {
        int n = s.size();
        long base = 26;
        long M = 1e9+9;
        int count = 1;
        long power = 1;
        long hash0 = 0;
        
        for (int len = 1; len <=n-1; len++)
        {            
            hash0 = (hash0 * base % M + s[len-1]-'a') % M;            
            power = (power * base) % M;
            
            unordered_set<long>Set({hash0});
            long hash = hash0;            
            for (int i=len; i<n; i++)
            {
                hash = (hash * base % M + (s[i]-'a')) % M; 
                hash = (hash - power*(s[i-len]-'a') % M + M) %M ;
                Set.insert(hash);
            }
            count += Set.size();
        }
        return count;        
    }
};
