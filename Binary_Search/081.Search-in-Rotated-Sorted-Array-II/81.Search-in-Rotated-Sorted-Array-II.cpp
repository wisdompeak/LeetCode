class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.size()==0) return false;
        
        int left=0;
        int right=nums.size()-1;
        int mid;
        
        while (left<right)
        {            
            while (left+1<right && nums[left]==nums[left+1])
                left++;
            mid=left+(right-left)/2;      
            
            if (nums[left]==target || nums[right]==target || nums[mid]==target) return true;
            
            if (nums[mid]>nums[left] && target>nums[left])
            {
                if (nums[mid]>target)
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if (nums[mid]>nums[left] && target<=nums[left])
                left=mid+1;
            else if (nums[mid]<=nums[left] && target>nums[left])
                right=mid-1;
            else if (nums[mid]<=nums[left] && target<=nums[left])
            {
                if (nums[mid]>target)
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        
        if (nums[left]==target) 
            return true;
        else
            return false;
    }
};
