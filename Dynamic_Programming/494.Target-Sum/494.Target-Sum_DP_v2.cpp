class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        unordered_map<int,int>Map;
        Map[0] = 1;
        
        for (auto x: nums)
        {
            auto Map_temp = Map;
            Map.clear();
            for (auto a: Map_temp)
            {
                Map[a.first+x] += a.second;
                Map[a.first-x] += a.second;
            }
        }
        return Map[S];
    }
};
