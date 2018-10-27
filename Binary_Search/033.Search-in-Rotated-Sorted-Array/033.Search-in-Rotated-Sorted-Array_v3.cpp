class Solution {
public:
    int search(vector<int>& nums, int target) 
    {    
        if (nums.size()==0) return -1;
        
        int left = 0;
        int right = nums.size()-1;
        
        while (left<=right)
        {
            int mid = (right-left)/2+left;
            int val;
            if (nums[mid]<nums[0] == target<nums[0])
                val = nums[mid];
            else if (target<nums[0])
                val = INT_MIN;
            else
                val = INT_MAX;
            
            if (val==target)
                return mid;
            else if (val<target)
                left = mid+1;
            else
                right = mid-1;                
        }
        
        return -1;
    }
};
