class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) 
    {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 < sum2)
            return minOperations(nums2, nums1);
        
        int diff = sum1 - sum2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = nums1.size()-1, j = 0;
        int count = 0;
        while (diff > 0)
        {
            if (i<0 && j==nums2.size())
                return -1;
            if (i<0)
            {
                diff -= (6 - nums2[j]);
                j++;
            }
            else if (j==nums2.size())
            {
                diff -= (nums1[i] - 1);
                i--;
            }
            else if (nums1[i] - 1> 6-nums2[j])
            {
                diff -= (nums1[i] - 1);
                i--;
            }
            else
            {
                diff -= (6 - nums2[j]);
                j++;
            }
            count++;            
        }
        
        return count;
    }
};
