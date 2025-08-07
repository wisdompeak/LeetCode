using ll = long long;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int j = 0;
        int ret = n;
        for (int i=0; i<n; i++) {
            while (j<n && (ll)nums[j]<=(ll)k*nums[i])
                j++;
            if (j==n)
                ret = min(ret, i);
            else
                ret = min(ret, i+n-j);
        }
        return ret;
    }
};
