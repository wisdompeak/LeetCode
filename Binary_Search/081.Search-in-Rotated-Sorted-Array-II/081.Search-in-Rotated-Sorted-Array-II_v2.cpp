class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        while (nums.size()>1 && nums.back()==nums[0])
            nums.pop_back();
        
        int left = 0;
        int right = nums.size()-1;
        
        while (left<right)
        {
            int mid = left+(right-left)/2;
            
            if (nums[mid] == target) return true;
            
            if (nums[mid]>=nums[0] == target>=nums[0])
            {
                if (nums[mid]<target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else if (target>=nums[0])
                right = mid-1;
            else
                left = mid+1;
        }
        
        if (left==right && nums[left]==target)
            return true;
        else
            return false;
    }
};
