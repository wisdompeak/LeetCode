class Solution {
    vector<int>presum;
    int n;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        this->n = n;
        presum.resize(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1]+nums[i-1];
                
        int ret = 0;
        int M = 1e9+7;
        for (int k = left; k <= right; k++)
            ret = (ret + kthSum(k))%M;
        return ret;        
    }
    
    int kthSum(int k)
    {
        int left = 1, right = presum.back();
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (smallerOrEqual(mid) < k)  // how many ranges whose sum is smaller or equal to mid
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    
    int smallerOrEqual(int s)
    {
        int j = 1;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (j<=n && presum[j]-presum[i]<=s)
                j++;
            count += j-i-1;
        }        
        return count;        
    }
};
