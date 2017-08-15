class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        
        vector<int>cumSum(nums.size()+1);
        cumSum[0]=0;
        for (int i=1; i<=nums.size(); i++)
            cumSum[i]=cumSum[i-1]+nums[i-1];

        vector<int>dp(nums.size()+1);
        dp[k]=1;               
        double result=(cumSum[k]-cumSum[0])*1.0/k;
        
        for (int i=k+1; i<=nums.size(); i++)
        {
            double maxAvg=INT_MIN;
            
            for (int j=dp[i-1]; j<=i-k+1; j++)
            {
                double avg= (cumSum[i]-cumSum[j-1])*1.0/(i-j+1);
                if (avg>maxAvg)
                {
                    maxAvg=avg;
                    dp[i]=j;
                }
                if (avg>result)
                    result=avg;
                
                // cout<<avg<<endl;
            }
        }
        
        return result;
    }
};
