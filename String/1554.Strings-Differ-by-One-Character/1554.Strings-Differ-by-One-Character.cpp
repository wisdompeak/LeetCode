class Solution {
public:
    bool differByOne(vector<string>& dict) 
    {
        long base = 261;
        long M = 1e9+7;
        int n = dict.size();
        int m = dict[0].size();
        vector<long>hash(n);
        for (int i=0; i<n; i++)
        {
            int h = 0;
            for (int j=0; j<m; j++)
                h = (h*base+dict[i][j]-'a')%M;
            hash[i] = h;
        }
        
        long K = 1;
        for (int j=m-1; j>=0; j--)
        {
            unordered_set<long>Set;            
            
            for (int i=0; i<n; i++)
            {
                long h = (hash[i] + M - (dict[i][j]-'a') * K % M) %M;
                if (Set.find(h)!=Set.end())
                    return true;
                Set.insert(h);
            }
            K = K*base%M;
        }
        
        return false;
    }
};
