typedef long long ll;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        unordered_map<int,int>Map;
        Map[0] = -1;

        ll sum = 0;
        for (auto a: nums)
            sum = (sum+a)%p;
        ll r0 = sum % p;
        if (r0==0) return 0;
        
        ll presum = 0;
        int ret = INT_MAX;
        
        for (int i=0; i<n; i++)
        {
            presum += nums[i];
            presum %= p;
            ll r = presum % p;
            ll diff = (r+p-r0) % p;            
            
            if (Map.find(diff)!=Map.end())
                ret = min(ret, i-Map[diff]);
            Map[r] = i;
        }
        
        if (ret>=n)
            return -1;
        else 
            return ret;
    }
};
