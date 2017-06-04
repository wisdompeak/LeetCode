class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int left=0;
        int right=0;
        
        while (right<nums.size())
        {
            if (nums[right]==0)
            {
                right++;
            }
            else
            {
                swap(nums[left],nums[right]);
                left++;
                right++;
            }
                
        }
        
    }
};
