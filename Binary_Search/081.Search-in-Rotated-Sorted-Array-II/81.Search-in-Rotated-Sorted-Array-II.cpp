class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.size()==0) return false;
        
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[left]==target ||nums[mid]==target ||nums[right]==target)
                return true;
                
            if (nums[left]==nums[mid])
                left++;
            else if (nums[left]<nums[mid] && nums[left]<target)
            {
                if (nums[mid]<target)
                    left = mid+1;
                else
                    right = mid;
            }
            else if (nums[left]<nums[mid] && nums[left]>target)
            {
                left = mid+1;
            }
            else if (nums[left]>nums[mid] && nums[left]<target)    
            {
                right = mid;
            }
            else if (nums[left]>nums[mid] && nums[left]>target)        
            {
                if (nums[mid]<target)
                    left = mid+1;
                else
                    right = mid;
            }
        }
        
        if (nums[left]==target) 
            return true;
        else
            return false;
        
    }
};
