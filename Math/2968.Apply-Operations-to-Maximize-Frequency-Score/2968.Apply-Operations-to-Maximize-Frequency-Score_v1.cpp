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
                    
        int j = 1;
        int ret = 0;
        for (int i=1; i<=n; i++)
        {
            while (j<=n && isOK(nums, presum, i, j, k))
            {
                ret = max(ret, j-i+1);
                j++;
            }
        }
        return ret;
    }

    bool isOK(vector<int>&nums, vector<LL>&presum, int i, int j, LL k)
    {
        int m = (i+j)/2;
        LL sum1 = (presum[j]-presum[m]) - (LL)nums[m]*(j-m);
        LL sum2 = (LL)nums[m]*(m-i) - (presum[m-1]-presum[i-1]);
        return sum1+sum2 <= k;
    }
    
};
