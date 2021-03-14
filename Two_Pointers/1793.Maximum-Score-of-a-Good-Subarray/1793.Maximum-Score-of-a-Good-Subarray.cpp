class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int l = k, r = k;
        int minVal = nums[k];
        int ret = 0;
        while (l>=0 || r < n)
        {
            while (l>=0 && nums[l]>=minVal) l--;
            while (r<n && nums[r]>=minVal) r++;
            ret = max(ret, (r-l-1)*minVal);            
            minVal = max(l>=0?nums[l]:INT_MIN, r<n?nums[r]:INT_MIN);            
        }
        return ret;
    }
};
