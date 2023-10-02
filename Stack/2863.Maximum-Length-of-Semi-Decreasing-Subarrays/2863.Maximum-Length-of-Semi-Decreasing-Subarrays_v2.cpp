class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int>stk;
        for (int i=0; i<n; i++)
        {
            if (stk.empty() || nums[i]>nums[stk.top()])
                stk.push(i);            
        }

        int ret = 0;
        for (int i=n-1; i>=0; i--)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                ret = max(ret, i-stk.top()+1);
                stk.pop();
            }            
        }
        return ret;
    }
};
