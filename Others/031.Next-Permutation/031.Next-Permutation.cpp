class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-1;
        while (i>=1 && nums[i]<=nums[i-1])
            i--;
        
        if (i==0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        
        i--;
        
        int j = nums.size()-1;
        while (nums[j]<=nums[i] && j>i)
            j--;
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
        return;
    }
};
