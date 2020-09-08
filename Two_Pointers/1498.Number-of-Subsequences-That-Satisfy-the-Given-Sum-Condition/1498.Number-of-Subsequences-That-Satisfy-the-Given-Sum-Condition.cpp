class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long M = 1e9+7;
        long ret = 0;
        vector<long>power(n+1);
            power[0] = 1;
        for (int i=1; i<=n; i++)
            power[i] = power[i-1] * 2 % M;

        int j = n-1;    
        for (int i=0; i<n; i++)
        {            
            while (j>=0 && nums[i]+nums[j] > target)
                j--;
            if (j<i) break;                        
            ret = (ret + power[j-i]) % M;
        }
        return ret;
    }
};
