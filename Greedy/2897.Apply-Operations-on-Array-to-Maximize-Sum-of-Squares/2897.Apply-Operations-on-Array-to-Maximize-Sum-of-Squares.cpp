using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) 
    {
        vector<int>count(32);
        
        for (int x: nums)
        {            
            for (int i=0; i<32; i++)
            {
                if ((x>>i)&1)
                    count[i] += 1;
            }            
        }        
        
        LL ret = 0;
        
        for (int t=0; t<k; t++)
        {
            LL x = 0;
            for (int i=31; i>=0; i--)
            {
                if (count[i]>0)
                {
                    x += (1LL<<i);
                    count[i]-=1;
                    x %= M;
                }
            }
            ret = ret + x*x%M;
            ret %= M;
        }
        
        return ret;
    }
};
