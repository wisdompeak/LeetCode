class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        unordered_map<int,vector<int>>Map;
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]].push_back(i);
        
        int ret = 0;
        for (auto& [key, pos]: Map)
        {
            int j = 0;
            for (int i=0; i<pos.size(); i++)
            {
                while (j<pos.size() && pos[j]-pos[i]+1-(j-i+1) <= k)
                {
                    ret = max(ret, j-i+1);
                    j++;
                }                
            }
        }
        return ret;
        
    }
};
