class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int>results;
        
        for (int i=0; i<nums.size(); i++)
        {
            while (nums[i]!=i+1 && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]!=i+1)
                results.push_back(nums[i]);
        }
        
        return results;
    }
};
