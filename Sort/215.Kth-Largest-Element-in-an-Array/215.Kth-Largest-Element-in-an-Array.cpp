class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        long left = INT_MIN, right = INT_MAX;
        while (left<right)
        {
            int mid = right-(right-left)/2;
            if (count(nums,mid) >=k)            
                left = mid;
            else
                right = mid-1;
        }  
        return left;
    }

    int count(vector<int>&nums, int t)
    {
        int ret = 0;
        for (auto x: nums)
            ret += (x>=t);
        return ret;
    }
};
