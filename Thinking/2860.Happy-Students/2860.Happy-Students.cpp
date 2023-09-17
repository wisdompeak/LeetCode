class Solution {
public:
    int countWays(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ret = 0;
        for (int i=0; i+1<n; i++)
        {
            if ((i+1 > nums[i]) && (i+1 < nums[i+1]))
                ret++;
        }
        
        if (0 < nums[0]) 
            ret++;
        if (n > nums[n-1])
            ret++;        
        
        return ret;
    }
};
