class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int k=0;
        for (int i=0; i<=nums.size(); i++)
            k = k^i;
        for (int i=0; i<nums.size(); i++)
            k = k^nums[i];
        return k;
    }
};
