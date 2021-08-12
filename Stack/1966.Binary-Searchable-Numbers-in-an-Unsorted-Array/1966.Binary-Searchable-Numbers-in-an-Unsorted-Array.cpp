class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>nextSmaller(n, n);
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() && nums[i]<nums[Stack.top()])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
                
        vector<int>prevGreater(n, -1);
        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() && nums[i]>nums[Stack.top()])
            {
                prevGreater[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        int count = 0;
        for (int i=0; i<n; i++)
        {
            if (nextSmaller[i]==n && prevGreater[i]==-1)
                count++;
        }
        return count;        
    }
};
