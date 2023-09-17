using LL = long long;
class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        int k = 1;
        LL ret = *max_element(nums.begin(), nums.end());
        while (k<n)
        {
            LL sum = 0;
            for (int i=1; i*i*k<=n; i++)
                sum += nums[i*i*k-1];            
            ret = max(sum, ret);
            k++;
        }
        
        return ret;
    }
};
