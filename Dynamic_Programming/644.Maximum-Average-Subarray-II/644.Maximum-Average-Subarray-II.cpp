class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int sum=0;
        for (int i=0; i<k; i++)
            sum+=nums[i];
        double maxAvg=sum*1.0/k;
        int len=k;                
        
        for (int i=k; i<nums.size(); i++)
        {
            sum+=nums[i];
            len++;
            
            double avg=sum*1.0/len;
            
            double tempSum=sum;
            double tempAvg;
            for (int j=i-len+1; j<=i-k; j++)
            {
                tempSum-=nums[j];
                tempAvg=tempSum*1.0/(i-j);
                
                if (tempAvg>avg)
                {
                    avg=tempAvg;
                    sum=tempSum;
                    len=i-j;
                }
            }
            
            if (avg>maxAvg)
            {
                maxAvg=avg;
            }
        }
        
        return maxAvg;
    }
};
