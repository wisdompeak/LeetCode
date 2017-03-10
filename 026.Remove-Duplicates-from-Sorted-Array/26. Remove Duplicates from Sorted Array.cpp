class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int left=0;
        int right=0;
        
        while (right<nums.size())
        {
            nums[left]=nums[right];
            left++;
            right++;
            
            while (right<nums.size() && nums[right]==nums[right-1])
                right++;
            
        }
        
        return left;
        
    }
};
