class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int ret = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        ret += helper(nums1,nums2);
        ret += helper(nums2,nums1);
        return ret;        
    }
    
    int helper(vector<int>& nums1, vector<int>& nums2)
    {
        int ret = 0;
        int n = nums2.size();
        for (long x: nums1)
        {
            int i = 0, j = n-1;
            while (i<j)
            {                
                if (x*x==(long)nums2[i]*(long)nums2[j])
                {
                    if (nums2[i]==nums2[j])
                    {
                        int t = j-i+1;
                        ret += t*(t-1)/2;
                        break;
                    }
                    else
                    {
                        int i0 = i; int j0=j;
                        while (i+1<n && nums2[i+1]==nums2[i])
                            i++;
                        while (j-1<n && nums2[j-1]==nums2[j])
                            j--;
                        ret += abs(i-i0+1)*abs(j0-j+1);
                        i++;
                        j--;                        
                    }
                }                    
                else if (x*x<(long)nums2[i]*(long)nums2[j])
                    j--;
                else
                    i++;
            }
        }
        return ret;
    }
};
