class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) 
    {        
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        vector<long>rets(n);        
        
        vector<long>pre(n);        
        pre[0] = nums[0];
        for (int i=1; i<n; i++)
            pre[i] = pre[i-1]+nums[i];        
        unordered_map<int,int>count;
        for (int i=0; i<n; i++)
        {
            int new_sum = sum + k-nums[i];
            if (new_sum % 2 == 0)
                rets[i] += count[new_sum/2];
            count[pre[i]]++;
        }
        
        vector<long>suf(n);        
        suf[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--)
            suf[i] = suf[i+1]+nums[i];
        count.clear();
        for (int i=n-1; i>=0; i--)
        {
            int new_sum = sum + k-nums[i];
            if (new_sum % 2 == 0)
                rets[i] += count[new_sum/2];
            count[suf[i]]++;
        }         
        
        long ret = 0;
        for (int i=0; i<n-1; i++)
        {
            if (pre[i]==sum-pre[i])
                ret++;
        }
        
        for (int i=0; i<n; i++)
            ret = max(ret, rets[i]);
        
        return ret;        
    }
};
