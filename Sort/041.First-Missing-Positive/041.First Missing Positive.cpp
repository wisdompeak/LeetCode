class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        if (nums.size()==0) return 1;        
        nums.insert(nums.begin(),0);
        
        for (int i=1; i<nums.size(); i++)
        {
            while (!(nums[i]<=0 || nums[i]>=nums.size() || nums[i]==i || nums[i]==nums[nums[i]]))
                swap(nums[i],nums[nums[i]]);
        }
        
        for (int i=1; i<nums.size(); i++)
            if (nums[i]!=i) return i;     
        
        return nums.size();
    }
};
