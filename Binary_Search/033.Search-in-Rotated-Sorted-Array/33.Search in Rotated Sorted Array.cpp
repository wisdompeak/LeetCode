class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        if (nums.size()==0) return -1;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            
            if (nums[mid]==target) return mid;
            
            if (nums[left]<=nums[mid] && nums[left]<=target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]>nums[mid] && nums[left]>target)
            {
                if (target<nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            else if (nums[left]<=nums[mid] && nums[left]>target)
                left = mid+1;
            else if (nums[left]>nums[mid] && nums[left]<=target)    
                right = mid;
                
        }
        
        if (nums[left]==target) 
            return left;
        else 
            return -1;
        
    }
};
