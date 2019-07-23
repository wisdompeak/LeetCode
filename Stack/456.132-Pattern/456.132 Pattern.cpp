class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        if (n<3) return false;
        
        vector<int>leftMin(n);
        leftMin[0] = INT_MAX;
        for (int i=1; i<n; i++)
            leftMin[i] = min(leftMin[i-1],nums[i-1]);
        
        stack<int>Stack;
        for (int i=n-1; i>=0; i--)
        {
            int second = INT_MIN;
            while (!Stack.empty() && Stack.top()<nums[i])
            {
                second = Stack.top();
                Stack.pop();
            }
                        
            if (leftMin[i]<second)
                return true;
            Stack.push(nums[i]);            
        }
        
        return false;
    }
};

