class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>results;
        
        if (nums.size()==0)
        {
            results.push_back(-1);
            results.push_back(-1);
            return results;
        }
        
        int left=0;
        int right=nums.size()-1;
        int mid;
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (nums[mid]<target)
                left = mid+1;
            else
                right = mid;
        }
        if (nums[left]==target)
            results.push_back(left);
        else
            results.push_back(-1);
            
        left=0;
        right=nums.size()-1;
        mid;
        while (left<right)
        {
            mid = left+(right-left)/2+1;
            if (nums[mid]>target)
                right = mid-1;
            else
                left = mid;
        }
        if (nums[left]==target)
            results.push_back(left);
        else
            results.push_back(-1);      
            
        return results;
        
        
    }
};
