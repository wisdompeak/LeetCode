class Solution {    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        long left = INT_MIN, right = INT_MAX;
        while (left < right)
        {
            long mid = left+(right-left)/2;
            long count = countSmallerOrEqual(mid, nums1, nums2);
            if (count < k)
                left = mid+1;
            else
                right = mid;
        }
        int m = left;

        vector<vector<int>>rets1;
        vector<vector<int>>rets2;
        for (int i=0; i<nums1.size(); i++)
        {
            int j=0;
            while (j<nums2.size() && nums1[i]+nums2[j]<=m)
            {
                if (nums1[i]+nums2[j]<m)
                    rets1.push_back({nums1[i], nums2[j]});
                else
                    rets2.push_back({nums1[i], nums2[j]});
                j++;
            }                
        }
        
        int t = min(rets2.size(), k - rets1.size());
        for (int i=0; i<t; i++)
            rets1.push_back(rets2[i]);
        return rets1;
    }

    long countSmallerOrEqual(int m, vector<int>& nums1, vector<int>& nums2)
    {
        int j = nums2.size()-1;
        long ret = 0;
        for (int i=0; i<nums1.size(); i++)
        {
            while (j>=0 && nums1[i]+nums2[j]>m)
                j--;
            ret += j+1;
        }
        return ret;
    }
};
