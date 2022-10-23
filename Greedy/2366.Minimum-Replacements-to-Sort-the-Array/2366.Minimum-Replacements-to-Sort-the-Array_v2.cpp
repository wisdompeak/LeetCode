using LL = long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        LL ret = 0;
        for (int i = nums.size()-2; i>=0; i--)
        {
            LL x = nums[i+1];
            LL y = nums[i];
            if (y<=x) continue;
                        
            if (y%x==0)
            {
                ret += y/x-1;
                nums[i] = x;                
            }
            else
            {
                int k = y/x+1;
                ret += y/x;
                nums[i] = y/k;
            }
        }
        
        return ret;
    }
};
