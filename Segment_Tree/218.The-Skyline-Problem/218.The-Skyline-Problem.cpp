class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        map<int, vector<pair<int,int>>>Map; // pos->{height, flag}
        for (auto building: buildings)
        {
            Map[building[0]].push_back({building[2], 1});
            Map[building[1]].push_back({building[2], -1});
        }
        
        multiset<int>Set;
        vector<vector<int>>rets;
        for (auto& [pos, pairs]: Map)
        {
            for (auto& [height, flag]: pairs)
            {
                if (flag == 1)
                    Set.insert(height);
                else
                    Set.erase(Set.find(height));                
            }

            int H = Set.empty() ? 0: *Set.rbegin();
            if (rets.empty() || rets.back()[1]!=H)
                rets.push_back({pos, H});
        }

        return rets;
    }
};
