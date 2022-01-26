class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ret(n);
        int sum = 0;
        for (int i=1; i<n; i++)
            sum += nums[i]-nums[0];
        ret[0] = sum;
        for (int i=1; i<n; i++)
        {
            sum += (i)*(nums[i]-nums[i-1]);
            sum -= (n-i)*(nums[i]-nums[i-1]);
            ret[i] = sum;
        }
        return ret;
        
    }
};
