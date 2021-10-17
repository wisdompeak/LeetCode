using LL = long long;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        if (nums1.size() > nums2.size())
            return kthSmallestProduct(nums2, nums1, k);
                
        LL left = -1e10, right = 1e10;
        while (left < right)
        {
            LL mid = left+(right-left)/2;
            LL count = countSmallerOrEqual(mid, nums1, nums2);
            if (count < k)
                left = mid+1;
            else
                right = mid;                
        }
        return left;
    }
    
    LL countSmallerOrEqual(LL mid, vector<int>& nums1, vector<int>& nums2)
    {
        LL ret = 0;
        
        if (mid >= 0)
        {
            int j0 = nums2.size()-1;
            int j1 = nums2.size()-1;
            
            for (int i=0; i<nums1.size(); i++)
            {
                if (nums1[i]>0)
                {
                    while (j0>=0 && (LL)nums1[i]*(LL)nums2[j0] > mid)
                        j0--;
                    ret += j0+1;
                }
                else if (nums1[i]==0)
                    ret += nums2.size();
                else
                {
                    while (j1>=0 && (LL)nums1[i]*(LL)nums2[j1] <= mid)
                        j1--;
                    ret += nums2.size()-1-j1;
                }
            }
        }
        else
        {
            int j0 = 0;
            int j1 = 0;
            
            for (int i=0; i<nums1.size(); i++)
            {
                if (nums1[i]>0)
                {
                    while (j0<nums2.size() && (LL)nums1[i]*(LL)nums2[j0] <= mid)
                        j0++;
                    ret += j0;
                }
                else if (nums1[i]==0)
                    ret += 0;
                else
                {
                    while (j1<nums2.size() && (LL)nums1[i]*(LL)nums2[j1] > mid)
                        j1++;
                    ret += nums2.size()-j1;
                }
            }
        }
        
        return ret;
    }
};
