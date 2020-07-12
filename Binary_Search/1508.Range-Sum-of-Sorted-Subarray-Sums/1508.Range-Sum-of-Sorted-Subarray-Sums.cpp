class Solution {
    vector<int>nums;
    int totalSum;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        this->nums = nums;
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ret = 0;
        int M = 1e9+7;
        
        for (int k = left; k <= right; k++)
            ret = (ret + kthSum(k))%M;
        return ret;        
    }
    
    int kthSum(int k)
    {
        int left = 1, right = totalSum;
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
        int j = 0;
        int count = 0;
        int sum  = 0;
        for (int i=0; i<nums.size(); i++)
        {            
            while (j<nums.size() && sum+nums[j]<=s)
            {
                sum+=nums[j];
                j++;
            }                
            count += j-i;
            sum -= nums[i];
        }
        return count;        
    }
};
