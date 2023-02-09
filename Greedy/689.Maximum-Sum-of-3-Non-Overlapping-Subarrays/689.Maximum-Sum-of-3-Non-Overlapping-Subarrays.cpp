class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>presum(n);        
        for (int i=0; i<n; i++)
            presum[i] = (i==0?0:presum[i-1]) + nums[i];
                        
        vector<int>leftMax(n,0);
        vector<int>leftIdx(n,0); 
        int maxSum = 0;
        int maxIdx = 0;
        for (int i=k-1; i<n; i++)
        {
            // [i-k+1 : i]
            int sum = presum[i] - (i<k?0:presum[i-k]);
            if (sum > maxSum)
            {
                maxSum = sum;
                maxIdx = i-k+1;
            }
            leftMax[i] = maxSum;
            leftIdx[i] = maxIdx;
        }

        vector<int>rightMax(n,0);
        vector<int>rightIdx(n,0); 
        maxSum = 0;
        maxIdx = 0;
        for (int i=n-k; i>=0; i--)
        {
            // [i : i+k-1]
            int sum = presum[i+k-1] - (i==0?0:presum[i-1]);
            if (sum >= maxSum)
            {
                maxSum = sum;
                maxIdx = i;
            }
            rightMax[i] = maxSum;
            rightIdx[i] = maxIdx;
        }

        vector<int>rets;
        maxSum = 0;
        for (int i=k; i+2*k<=n; i++)
        {
            int sum = presum[i+k-1] - (i==0?0:presum[i-1]);
            if (sum + leftMax[i-1] + rightMax[i+k] > maxSum)
            {
                maxSum = sum + leftMax[i-1] + rightMax[i+k];
                rets = {leftIdx[i-1], i, rightIdx[i+k]};
            }
        }

        return rets;
    }
};
