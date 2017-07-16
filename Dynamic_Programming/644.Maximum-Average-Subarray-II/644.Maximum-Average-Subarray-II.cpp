class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        vector<int>CumSum(nums.size(),0);
        CumSum[0]=nums[0];
        for (int i=1; i<nums.size(); i++)
            CumSum[i]=CumSum[i-1]+nums[i];
                
        vector<int>dp(nums.size(),0);  // record the length of the optimal subarray that ends in nums[i]
        dp[k-1]=k;
        double maxAvg=CumSum[k-1]*1.0/k;;
    
        for (int i=k; i<nums.size(); i++)
        {
            double avg = -INT_MIN;            
            for (int j=i-dp[i-1]; j<=i-k+1; j++)
            {
                double tempSum=CumSum[i]-CumSum[j-1];
                int div = i-j+1;
                double tempAvg = tempSum/div;
                
                if (tempAvg>avg)
                {
                    avg=tempAvg;
                    dp[i]=i-j+1;
                }
            }
            
            maxAvg = max(maxAvg, (CumSum[i]-CumSum[i-dp[i]])*1.0/dp[i]);
        }
        
        return maxAvg;
        
    }
};
