using LL = long long;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<LL>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+nums[i];

        int i=1;
        int ret = 0;
        for (int j=1; j<=n; j++)
        {
            while (!isOK(nums, presum, i, j, k))
                i++;
            ret = max(ret, j-i+1);
        }
        return ret;        
    }

    bool isOK(vector<int>&nums, vector<LL>&presum, int i, int j, int k)
    {
        LL detla = (LL)nums[j]*(j-i+1) - (presum[j] - presum[i-1]);
        return detla <= k;
    }
};
