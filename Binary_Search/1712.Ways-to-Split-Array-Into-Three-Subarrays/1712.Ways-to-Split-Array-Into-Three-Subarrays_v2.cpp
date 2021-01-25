class Solution {
public:
    int waysToSplit(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>presum(n,0);
        presum[0] = nums[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+nums[i];
        
        int j = 0, k = 0;
        long long ret = 0;
        long long M = 1e9+7;
        for (int i=0; i<n; i++)
        {
            while (j<=i || (j<n && presum[j]-presum[i] < presum[i]))
                j++;
            if (j==n) break;
            
            while (k+1<n-1 && presum[k+1]*2<=presum[i]+presum[n-1])
                k+=1;                        
            
            if (k<j) continue;
            
            ret += k-j+1;
            ret %= M;
        }        
        return ret;        
    }
};
