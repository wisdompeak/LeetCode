using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int sumOfPower(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        LL sum = 0;
        LL ret = 0;
        
        for (int i=0; i<nums.size(); i++)
        {
            LL mx = (LL)nums[i]*(LL)nums[i]%M;
            
            if (i>=1)
                sum = sum * 2 % M + (LL)nums[i-1];
            
            ret += mx * sum % M + mx * nums[i] % M;
            ret %= M;
        }
        
        return ret;
    }
};
