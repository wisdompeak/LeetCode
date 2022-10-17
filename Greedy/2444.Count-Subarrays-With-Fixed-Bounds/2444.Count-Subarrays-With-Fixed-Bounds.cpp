class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {       
        long long ret = 0;
        int prevMin = -1, prevMax = -1, boundary = -1;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]<minK ||  nums[i]>maxK)
            {
                boundary = i;
                continue;
            }

            if (nums[i] == minK)
                prevMin = i;
            if (nums[i] == maxK)
                prevMax = i;

            ret += max(0, min(prevMin, prevMax) - boundary);
        }

        return ret;
    }
};
