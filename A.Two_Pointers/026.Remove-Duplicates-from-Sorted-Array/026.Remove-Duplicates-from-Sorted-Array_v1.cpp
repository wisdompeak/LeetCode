class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0;
        int j=1;
        
        while (j<nums.size())
        {
            if (nums[j]==nums[j-1])
            {
                j++;
            }
            else
            {
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return i+1;
    }
};
