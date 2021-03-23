class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>leftMin(n);
        leftMin[0] = INT_MAX;
        for (int i=1; i<n; i++)
        {
            leftMin[i] = min(leftMin[i-1], nums[i-1]);
        }
        
        stack<int>Stack;
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[i]>nums[Stack.top()])
            {
                if (leftMin[i] < nums[Stack.top()])
                    return true;
                Stack.pop();
            }            
            Stack.push(i);
        }
        return false;
    }
};
