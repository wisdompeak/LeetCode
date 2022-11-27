class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        for (auto& x: nums)
        {
            if (x>k) x=1;
            else if (x==k) x=0;
            else x=-1;
        }
        
        unordered_map<int, int>oddSum;
        unordered_map<int, int>evenSum;
        
        evenSum[0] = 1;
        
        int sum = 0;
        int ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if (i%2==0)
            {
                ret += evenSum[sum-0];
                ret += oddSum[sum-1];
                oddSum[sum] += 1;
            }
            else
            {
                ret += oddSum[sum-0];
                ret += evenSum[sum-1];
                evenSum[sum] += 1;
            }
        }
        
        return ret;
        
    }
};
