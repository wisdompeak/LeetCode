class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());
        
        long long ret = 0;
        for (int x: nums)
        {
            int k = upper_bound(nums.begin(), nums.end(), upper-x) - nums.begin();
            int t = lower_bound(nums.begin(), nums.end(), lower-x) - nums.begin();
            int count = k-t;
            
            if (x+x<=upper && x+x>=lower)
                count--;
            
            ret += count;            
        }
        
        return ret/2;
        
    }
};
