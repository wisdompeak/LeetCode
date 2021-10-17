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
            if (checkNums(mid, nums1, nums2) >= k)
                right = mid;
            else
                left = mid+1;                
        }
        return left;
    }
    
    LL checkNums(LL mid, vector<int>& nums1, vector<int>& nums2)
    {
        LL ret = 0;
        for (int i=0; i<nums1.size(); i++)
        {
            LL x = nums1[i];
            
            if (x == 0)
            {
                if (mid < 0) ret+=0;
                else ret+=nums2.size();                                
            }
            else if (x > 0)
            {
                LL yy = floor(mid*1.0/x);                    
                auto iter = upper_bound(nums2.begin(), nums2.end(), yy);
                ret += (iter-nums2.begin());              
            }
            else
            {
                LL yy = ceil(mid*1.0/x);
                auto iter = lower_bound(nums2.begin(), nums2.end(), yy);
                ret += nums2.size() - (iter-nums2.begin());                      
            }            
        }
        
        return ret;
    }
};
