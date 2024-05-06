using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if (n<=2)
        {
            return (LL)(nums[n-1]-nums[0])*cost1%M;
        }
        
        LL total = accumulate(nums.begin(), nums.end(), 0LL);
        
        cost2 = min(cost1*2, cost2);
        int m = nums.back();
        LL ret = LLONG_MAX;
        for (int limit = m; limit <= 2*m; limit++)
        {
            LL diff0 = limit - nums[0];
            LL diff_all = (LL)limit*n - total;
            
            LL ans;
            if (diff0 <= diff_all/2)
            {
                ans = diff_all/2*cost2 + (diff_all%2==1?cost1:0);
            }
            else
            {
                ans = (diff_all - diff0)*cost2 + (diff0 - (diff_all - diff0))*cost1;
            }
            
            ret = min(ret, ans);
        }
        
        return ret%M;
        
    }
};
