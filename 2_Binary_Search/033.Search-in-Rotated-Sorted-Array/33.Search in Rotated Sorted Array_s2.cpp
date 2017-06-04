class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.size()==0) return -1;
        
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[left]==target) return left;
            if (nums[right]==target) return right;
            if (nums[mid]==target) return mid;
            
            if (target>=nums[0] && nums[mid]>=nums[0] || target<nums[0] && nums[mid]<nums[0])
            {
                if (nums[mid]>target)
                    right=mid;
                else
                    left=mid+1;
            }
            else if (target>=nums[0] && nums[mid]<nums[0])
                right=mid;
            else if (target<nums[0] && nums[mid]>=nums[0])
                left=mid+1;
        }
        
        if (nums[left]==target)
            return left;
        else
            return -1;
    }
};
