class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while (left<right)
        {
            if (left==right-1)
              return min(nums[left],nums[right]);
            
            mid = left+(right-left)/2;
            
            if (nums[left]==nums[mid]) 
                left++;
            else if (nums[left]<nums[right] && nums[left]<nums[mid])
            {
                right = mid;
            }
            else if (nums[left]<nums[right] && nums[left]>nums[mid])
            {
                // impossible;
            }
            else if (nums[left]>=nums[right] && nums[left]<nums[mid])
            {
                left = mid+1;
            }
            else if (nums[left]>=nums[right] && nums[left]>nums[mid])
            {
                right = mid;
            }
            
        }
        
        return nums[left];
        

    }
};
