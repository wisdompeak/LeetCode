using LL = long long;
class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        int n = nums.size();

        int k = 1;
        LL ret = 0;
        while (k<=n)
        {
            LL sum = 0;
            for (int i=1; k*i*i<=n; i++)
                sum += nums[k*i*i-1];
            ret = max(ret, sum);
            k++;
        }

        return ret;
    }
};
