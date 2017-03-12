class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        
        while (mid<=right)
        {
            if (nums[mid]==2)
            {
                swap(nums[mid],nums[right]);
                right--;
            }
            else if (nums[mid]==0)
            {
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else
            {
                mid++;
            }
        }
        
    }
};
