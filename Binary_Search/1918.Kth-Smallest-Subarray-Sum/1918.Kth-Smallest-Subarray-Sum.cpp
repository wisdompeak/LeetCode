class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) 
    {
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            if (countOK(nums, mid, k)) // # of subarrays whose sum <= mid is at least k
                right = mid;
            else
                left = mid+1;                
        }
        return left;        
    }
    
    bool countOK(vector<int>&nums, long long target, int k)
    {
        int count = 0;
        long long sum = 0;
        int j = 0;
        
        for (int i=0; i<nums.size(); i++)
        {            
            while (j<nums.size() && sum+nums[j]<=target)
            {
                sum+=nums[j];
                j++;
            }                
            count+=j-i;            
            sum -= nums[i];
            if (count>=k) return true;
        }
        return false;
    }
};
