class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {        
        long long dp_even = 0;
        long long dp_odd = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            long long dp_even_2 = dp_even;
            long long dp_odd_2 = dp_odd;
            
            dp_even = max(dp_even_2, dp_odd_2 + nums[i]);
            dp_odd = max(dp_odd_2, dp_even_2 - nums[i]);
        }
        
        return dp_even;
    }
};
