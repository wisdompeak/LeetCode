class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
        auto arr = nums1;
        sort(arr.begin(), arr.end());
        int n = nums2.size();
        int maxDecrease = 0;
        
        for (int i=0; i<n; i++)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), nums2[i]);
            int a = INT_MAX, b = INT_MAX;
            if (iter!=arr.end())
                a = *iter;
            if (iter!=arr.begin())
                b = *prev(iter);
            
            int diff = INT_MAX;
            if (a!=INT_MAX)
                diff = min(diff, abs(a-nums2[i]));
            if (b!=INT_MAX)
                diff = min(diff, abs(b-nums2[i]));
            
            int origin = abs(nums1[i]-nums2[i]);
            
            maxDecrease = max(maxDecrease, origin - diff);            
        }
        
        long ret = 0;
        long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            ret = ret + abs((long)nums1[i] - (long)nums2[i]);
            ret %= M;
        }
        ret -= maxDecrease;
        ret = (ret+M)%M;
        
        return ret;
    }
};
