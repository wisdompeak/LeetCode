class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) 
    {
        int ret = 0;
        int n = arr.size();
        
        for (int t=0; t<k; t++)
        {
            vector<int>nums;
            for (int i=t; i<n; i+=k)
                nums.push_back(arr[i]);
            ret += nums.size() - lengthOfLIS(nums);            
        }
        
        return ret;
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();              
        vector<int>q(n, INT_MAX);
        for (int i=0; i<n; i++)
        {
            auto iter = upper_bound(q.begin(),q.end(),nums[i]);
            *iter = nums[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (q[i] != INT_MAX)
                return i + 1;  
        }
        return 0;    
    }
};
