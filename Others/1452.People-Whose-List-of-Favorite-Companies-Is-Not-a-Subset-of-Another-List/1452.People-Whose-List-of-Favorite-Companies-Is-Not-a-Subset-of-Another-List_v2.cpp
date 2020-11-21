class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) 
    {        
        int n = favoriteCompanies.size();
        unordered_map<string,bitset<100>>c2p;
        for (int i=0; i<n; i++)
            for (int j=0; j<favoriteCompanies[i].size(); j++)
                c2p[favoriteCompanies[i][j]][i] = 1;

        vector<int>rets;
        bitset<100>state;
        for (int i=0; i<n; i++)
        {            
            state.set();
            
            for (string c: favoriteCompanies[i])
            {
                state = state & c2p[c];
            }
            if (state.count()==1)
                rets.push_back(i);
        }        
        return rets;
    }
};
