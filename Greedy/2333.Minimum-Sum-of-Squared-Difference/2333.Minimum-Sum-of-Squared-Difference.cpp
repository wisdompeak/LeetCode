using LL = long long;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        vector<LL>nums;
        for (int i=0; i<nums1.size(); i++)
            nums.push_back(abs(nums1[i]-nums2[i]));
        sort(nums.rbegin(), nums.rend());
        
        int n = nums.size();
        int cap = k1+k2;
        vector<LL>presum(n);
        presum[0] = nums[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+nums[i];
        LL ret = 0;
        
        if (presum[n-1] <= cap)
            return 0;
        
        int k = 0;
        while (k<n && (presum[k] - nums[k]*(k+1) <= cap))
            k++;
        
        k--;
        
        LL diff = cap - (presum[k] - nums[k]*(k+1));
        LL avg = diff / (k+1);
        LL b = diff - avg*(k+1);
        LL a = (k+1-b);
                        
        for (int i=0; i<a; i++ )         
        {
            LL t = max(0LL, nums[k]-avg);
            ret += t*t;
        }
                    
        for (int i=0; i<b; i++ )
        {
            LL t = (nums[k] - avg - 1);
            ret += t*t;
        }            
        
        for (int i=k+1; i<n; i++)            
            ret += (nums[i])*nums[i];
                
        return ret;
        
    }
};
