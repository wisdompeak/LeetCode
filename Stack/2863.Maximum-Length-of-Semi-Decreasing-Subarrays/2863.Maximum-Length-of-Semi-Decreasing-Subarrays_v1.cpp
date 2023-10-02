class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) 
    {
        int n = nums.size();
        vector<pair<int,int>>arr;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            auto iter = upper_bound(arr.begin(), arr.end(), make_pair(nums[i], INT_MAX));
            if (iter!=arr.end())
            {
                int k = iter->second;
                ret = max(ret, i-k+1);
            }
            if (arr.empty() || nums[i]>arr.back().first)
                arr.push_back({nums[i], i});
        }
        return ret;
    }
};
