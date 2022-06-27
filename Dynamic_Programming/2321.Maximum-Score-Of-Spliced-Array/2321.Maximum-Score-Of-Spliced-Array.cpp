class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
        return max(solve(nums1,nums2), solve(nums2,nums1));
    }
    int solve(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        vector<int>nums(n);
        for (int i=0; i<n; i++)
        {
            nums[i] = nums1[i]-nums2[i];
        }
        
        int curSum = 0;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            curSum = max(curSum + nums[i], nums[i]);
            ret = max(ret, curSum);
        }
        
        int sum = accumulate(nums2.begin(), nums2.end(), 0);
        
        return sum + ret;        
    }
};
