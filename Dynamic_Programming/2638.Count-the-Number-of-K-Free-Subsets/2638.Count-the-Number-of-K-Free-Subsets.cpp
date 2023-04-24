class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) 
    {
        vector<vector<int>>arr(k);
        for (int x: nums)
            arr[x%k].push_back(x);

        long long ret = 1;
        for (int i=0; i<k; i++)
            ret *= helper(arr[i], k);

        return ret;
    }

    long long helper(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        long long take = 0, no_take = 1;
        for (int i=0; i<nums.size(); i++)
        {            
            long long take_temp = take, no_take_temp = no_take;
            if (i>=1 && nums[i] == nums[i-1]+k)
            {
                take = no_take_temp;
                no_take = take_temp + no_take_temp;
            }
            else
            {
                take = take_temp + no_take_temp;
                no_take = take_temp + no_take_temp;
            }
        }
        return take + no_take;
    }
};
