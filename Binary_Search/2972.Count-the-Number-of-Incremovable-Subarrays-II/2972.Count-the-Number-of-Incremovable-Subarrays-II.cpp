using LL = long long;
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) 
    {        
        int n = nums.size();
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);

        int l = 1;
        while (l<=n)
        {
            if (nums[l]<nums[l+1]) l++;
            else break;
        }
        int r = n;
        while (r>0)
        {
            if (nums[r]>nums[r-1]) r--;
            else break;
        }
        if (r<l)
        {
            return (LL)n*(n-1)/2+n;
        }

        LL ret = 0;
        for (int i=0; i<=l; i++)
        {
            auto iter = upper_bound(nums.begin()+r, nums.end(), nums[i]);
            ret += nums.end()-iter;
        }

        return ret;
    }
};
