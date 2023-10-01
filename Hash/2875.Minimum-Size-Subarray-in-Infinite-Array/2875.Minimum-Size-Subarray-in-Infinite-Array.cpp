using LL = long long;
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) 
    {
        LL total  = accumulate(nums.begin(), nums.end(), 0LL);

        int n = nums.size();
        for (int i=0; i<n; i++)
            nums.push_back(nums[i]);

        vector<LL>presum(2*n, 0);
        presum[0] = nums[0];
        for (int i=1; i<2*n; i++)
            presum[i] = presum[i-1] +  nums[i];

        LL ret = INT_MAX/2;

        unordered_map<LL, int>Map; // presum module, index
        Map[0] = -1;
        for (int i=0; i<2*n; i++)
        {
            LL r = ((presum[i] - target) % total + total) % total;

            if (Map.find(r)!=Map.end())
            {
                int j = Map[r];
                LL k = ((j==-1? 0: presum[j]) - presum[i] + target) / total;
                ret = min(ret, i-j+k*n);
            }

            Map[presum[i]%total] = i;
        }

        if (ret == INT_MAX/2) return -1;
        else return ret;        
    }
};
