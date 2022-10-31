using LL = long long;
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) 
    {
        int len = 0;
        int ret = 0;
        
        sort(nums.rbegin(), nums.rend());
                        
        unordered_map<int,int>dp;
                
        for (int i=0; i<nums.size(); i++)
        {    
            int r = nums[i]%space;
            dp[r] = dp[r] + 1;            
            
            if (dp[r] > len)
            {
                ret = nums[i];
                len = dp[r];
            }                
            else if (dp[r] == len)
            {
                ret = nums[i];
            }
            
        }
        
        return ret;
    }
};
