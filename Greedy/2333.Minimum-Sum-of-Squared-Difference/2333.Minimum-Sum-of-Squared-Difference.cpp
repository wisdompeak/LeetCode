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
        vector<LL>presum(n);
        presum[0] = nums[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+nums[i];
        LL ret = 0;
        
        int k = k1+k2;
        if (presum[n-1] <= k)
            return 0;        
        
        int i = 0;
        while (i<n && (presum[i] - nums[i]*(i+1) <= k))
            i++;        
        i--;
        
        LL diff = k - (presum[i] - nums[i]*(i+1));
        LL each = diff / (i+1);
        LL extra = diff % (i+1);

        int a = extra;  // nums[i]-each-1;
        int b = i+1-a;  // nums[i]-each;
        
        ret += (nums[i]-each-1)*(nums[i]-each-1) * a;
        ret += (nums[i]-each)*(nums[i]-each) * b;                        
        
        for (int j=i+1; j<n; j++)            
            ret += nums[j]*nums[j];
                
        return ret;
    }
};
