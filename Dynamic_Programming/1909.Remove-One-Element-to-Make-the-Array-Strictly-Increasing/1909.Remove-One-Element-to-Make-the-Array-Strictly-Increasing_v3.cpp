class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        for (int i=0; i+1<nums.size(); i++)
        {
            if (nums[i] >= nums[i+1])
            {
                return check(nums,i) || check(nums,i+1);
            }            
        }
        return true;
    }

    bool check(vector<int>&nums, int k)
    {
        int cur = INT_MIN;
        for (int i=0; i<nums.size(); i++)
        {
            if (i==k) continue;
            if (cur >= nums[i]) return false;
            cur = nums[i];
        }
        return true;
    }
};
