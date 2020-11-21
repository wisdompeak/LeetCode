class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) 
    {
        int n = favoriteCompanies.size();
        unordered_map<string, bitset<100>>c2p;
        for (int i=0; i<n; i++)
            for (int j=0; j<favoriteCompanies[i].size(); j++)
                c2p[favoriteCompanies[i][j]][i]=1;
        
        vector<int>ret;
        for (int i=0; i<n; i++)
        {
            bitset<100>bs;
            bs.set();
            
            for (string c: favoriteCompanies[i])
            {
                bs &= c2p[c];
            }
            if (bs.count()==1)
                ret.push_back(i);
        }
        return ret;        
    }
};
