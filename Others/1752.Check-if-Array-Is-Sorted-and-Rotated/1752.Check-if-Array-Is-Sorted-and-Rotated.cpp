class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int i = 0;
        while (i+1<nums.size() && nums[i]<=nums[i+1])
            i++;
        if (i==nums.size()-1)
            return true;
        i++;
        while (i+1<nums.size() && nums[i]<=nums[i+1])
            i++;
        if (i!=nums.size()-1)
            return false;
        if (nums.back() > nums[0])
            return false;
        return true;
    }
};
