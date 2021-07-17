class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        int n = nums.size();
        vector<int>prevGreaterOrEqual(n,-1);
        vector<int>nextGreater(n,n);

        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && nums[Stack.top()] < nums[i])
            {
                nextGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[Stack.top()] <= nums[i])
            {
                prevGreaterOrEqual[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (nums[i]>=left && nums[i]<=right)
            {
                ret += (i-prevGreaterOrEqual[i])*(nextGreater[i]-i);
            }            
        }
        return ret;
    }
};
