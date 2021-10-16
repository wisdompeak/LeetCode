class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) 
    {
        vector<int>presum(nums.size()+1);        
        for (int i=0; i<nums.size(); i++)
            presum[i+1] = presum[i]+nums[i];  
                
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int mid = left + (right-left)/2;
            
            int count = countSmallerOrEqual(mid, presum); // # of diff <= mid
            
            if (count >= k) 
                right = mid;
            else
                left = mid+1;                
        }
        return left;        
    }
    
    int countSmallerOrEqual(int t, vector<int>&presum)
    {
        int ret = 0;
        // for (int i=0; i<presum.size(); i++)
        // {
        //     auto iter = upper_bound(presum.begin(), presum.end(), t+presum[i]);
        //     ret += iter - (presum.begin()+i+1);
        // }
        int j = 0;
        for (int i=0; i<presum.size(); i++)
        {
            while (j<presum.size() && presum[j]-presum[i]<=t)            
                j++;
            ret+=j-(i+1);
        }
        return ret;
    }
};
