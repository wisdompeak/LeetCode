using LL = long long;
class Solution {
    vector<LL>presum;
public:
    int maxFrequencyScore(vector<int>& nums, long long k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        presum.resize(n);
        for (int i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1]) + nums[i];
            
        
        int left = 1, right = n;
        while (left < right)
        {
            int mid = right-(right-left)/2;
            if (isOK(nums, k, mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    
    bool isOK(vector<int>&nums, LL k, int len)
    {        
        for (int i=0; i+len<=nums.size(); i++)
        {
            LL m = i+len/2;
            LL j = i+len-1;
            LL sum1 = nums[m]*(m-i+1) - (presum[m] - (i==0?0:presum[i-1]));
            LL sum2 = (presum[j] - (m==0?0:presum[m-1])) - nums[m]*(j-m+1);
            if (sum1+sum2<=k)
            {
                return true;
            }
                
        }
        return false;
    }
};
