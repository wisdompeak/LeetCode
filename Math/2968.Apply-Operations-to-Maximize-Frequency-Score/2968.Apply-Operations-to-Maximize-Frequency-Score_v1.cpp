using LL = long long;
class Solution {    
public:
    int maxFrequencyScore(vector<int>& nums, long long k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        nums.insert(nums.begin(), 0);                
        vector<LL>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1] + nums[i];
                    
        int left = 1, right = n;
        while (left < right)
        {
            int mid = right-(right-left)/2;
            if (isOK(nums, presum, k, mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    
    bool isOK(vector<int>&nums, vector<LL>presum, LL k, int len)
    {        
        int n = nums.size()-1;
        for (int i=1; i+len-1<=n; i++)
        {
            LL m = i+len/2;
            LL j = i+len-1;
            LL sum1 = nums[m]*(m-i+1) - (presum[m] - presum[i-1]);
            LL sum2 = (presum[j] - presum[m-1]) - nums[m]*(j-m+1);
            if (sum1+sum2<=k) return true;                
        }
        return false;
    }
};
