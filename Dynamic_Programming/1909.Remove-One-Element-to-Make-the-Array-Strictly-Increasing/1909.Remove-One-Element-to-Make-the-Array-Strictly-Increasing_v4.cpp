class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        vector<int>arr;
        for (auto x: nums)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), x);
            if (iter!=arr.end())
                *iter = x;
            else
                arr.push_back(x);
        }
        return arr.size() >= nums.size()-1;
    }
};
