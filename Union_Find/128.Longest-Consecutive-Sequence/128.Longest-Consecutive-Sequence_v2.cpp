class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int>Set;
        for (auto a:nums)
            Set.insert(a);
        
        int result = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (Set.find(nums[i]-1)!=Set.end())
                continue;
            int j = nums[i]+1;
            while (Set.find(j)!=Set.end())
                j++;
            
            result = max(result, j-nums[i]);
        }
        return result;
    }
};
