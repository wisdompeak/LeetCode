class Solution {
public:
    int findMin(vector<int>& nums) 
    {

        int left=0;
        int right=nums.size()-1;
        int mid;
        
        while (left<right)
        {
            while (left+1<right && nums[left]==nums[left+1])
                left++;
                
            mid=left+(right-left)/2;
            if (left==right-1) return min(nums[left],nums[right]);
            
            if (nums[left]<nums[mid] && nums[left]<nums[right])
                right=mid;  // return nums[left];
            else if (nums[left]<nums[mid] && nums[left]>=nums[right])
                left=mid+1;
            else if (nums[left]>=nums[mid] && nums[left]<nums[right])
                continue;
            else if (nums[left]>=nums[mid] && nums[left]>=nums[right])
                right=mid;    
        }
        
        return nums[left];
    }
};
