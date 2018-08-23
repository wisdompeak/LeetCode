class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double low = INT_MAX, high = INT_MIN;
        for (int i:nums)
        {
            low = min((int)low,i);
            high = max((int)high,i);
        }
    
        while (high-low>1e-6)
        {
            double mid = (high-low)/2+low;
            
            if (check(nums,mid,k))
                low = mid;
            else
                high = mid;            
        }
        
        return high;
    }
    
    bool check(vector<int>&nums, double avg, int k)
    {
        int N = nums.size();
        vector<double> prefixSum(N+1,0);
        
        for (int i=1; i<k; i++)
            prefixSum[i] = prefixSum[i-1]+nums[i-1]-avg;

        double preMin = 0;
        
        for (int i=k; i<=N; i++)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i-1]-avg;
            
            if(prefixSum[i] > preMin) 
                return true;
            preMin = min(preMin, prefixSum[i-k+1]);
        }
        return false;
    }
};
