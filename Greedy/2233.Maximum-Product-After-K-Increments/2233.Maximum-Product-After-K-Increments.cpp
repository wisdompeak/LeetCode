using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<LL>presum(n);
        for (int i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1]) + (LL)nums[i];
        
        vector<LL>diff(n);
        for (int i=0; i<n; i++)
            diff[i] = (LL)nums[i]*(i+1)-presum[i];
        
        auto iter = upper_bound(diff.begin(), diff.end(), k);
        int p = prev(iter) - diff.begin();
        
        LL total = presum[p] + k;
        LL each = total / (p+1);
        LL extra = total % (p+1);
        
        LL ret = 1;
        for (int i=0; i<extra; i++)
            ret = ret * (each+1) % M;
        for (int i=extra; i<p+1; i++)
            ret = ret * (each) % M;
        for (int i=p+1; i<n; i++)
            ret = ret * nums[i] % M;
        
        return ret;
    }
};
