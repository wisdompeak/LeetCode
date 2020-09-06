class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int ret = 0;
        ret += helper(nums1, nums2);
        ret += helper(nums2, nums1);
        return ret;
    }

    int helper(vector<int>& nums1, vector<int>& nums2)
    {
        int ret = 0;                
        for (long x: nums1)
        {
            unordered_map<int,int>Map;
            for (int i=0; i<nums2.size(); i++)
            {
                if (x*x%nums2[i]==0)
                {
                    ret += Map[x*x/nums2[i]];
                }
                Map[nums2[i]]+=1;
            }
        }
        return ret;
    }
};
