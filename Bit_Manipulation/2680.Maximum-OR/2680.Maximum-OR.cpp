using LL = long long;
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {       
        vector<int>count(32);
        
        for (int i = 0; i< nums.size(); i++)
        {
            for (int j=0; j<=31; j++)
            {
                if ((nums[i]>>j)&1)
                    count[j]++;
            }
        }
        
        LL ret = 0;
        for (int i = 0; i< nums.size(); i++)
        {
            auto temp = count;
            for (int j=0; j<=31; j++)
            {
                if ((nums[i]>>j)&1)
                    temp[j]--;
            }
            LL ans = 0;
            for (int j=0; j<=31; j++)
            {
                if (temp[j]>0)
                    ans += (1<<j);
            }
            ans |= ((LL)nums[i]<<k);
            ret = max(ans, ret);
        }
        
        return ret;
    }
};
