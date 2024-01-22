class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        set<pair<int,int>>Set;
        int n = nums.size();
        vector<int>pointers;
        for (int i=0; i<n; i++)
        {
            pointers.push_back(0);
            Set.insert({nums[i][0],i});
        }

        int range = INT_MAX;
        vector<int>ret;
        while (1)
        {
            if (Set.rbegin()->first - Set.begin()->first < range)
            {
                range = Set.rbegin()->first - Set.begin()->first;
                ret = {Set.begin()->first, Set.rbegin()->first};
            }            
            int i = Set.begin()->second;
            pointers[i]++;
            if (pointers[i]==nums[i].size()) break;
            Set.erase(Set.begin());
            Set.insert({nums[i][pointers[i]],i});
        }

        return ret;
    }
};
