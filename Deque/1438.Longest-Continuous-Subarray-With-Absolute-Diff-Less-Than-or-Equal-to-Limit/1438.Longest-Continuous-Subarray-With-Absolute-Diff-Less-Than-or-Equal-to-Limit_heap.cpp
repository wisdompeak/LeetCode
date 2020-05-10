class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int>Set({nums[0]});
        int j = 0;
        int ret = 0;        
        
        for (int i=0; i<nums.size(); i++)
        {            
            while (*Set.rbegin()-*Set.begin()<=limit)
            {
                ret = max(ret, j-i+1);
                j++;
                if (j>=nums.size()) break;
                Set.insert(nums[j]);
            }

            if (j>=nums.size()) break;
            
            Set.erase(Set.find(nums[i]));     
        }
        
        return ret;
    }
};
