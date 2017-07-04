class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        if (nums.size()<3) return false;
        
        vector<int>prevMin(nums.size());
        prevMin[0]=INT_MIN;
        for (int i=1; i<nums.size(); i++)
            prevMin[i]=min(prevMin[i-1],nums[i-1]);
        
        stack<int>Stack;
        int small=INT_MIN;
        for (int i=nums.size()-1; i>=0; i--)
        {
            if (Stack.empty() || nums[i]<=Stack.top())
                Stack.push(nums[i]);
            else
            {
                while (!Stack.empty() && nums[i]>Stack.top())
                {
                    small=max(small,Stack.top());
                    Stack.pop();
                }
                Stack.push(nums[i]);
            }
            if (nums[i]<small) return true;
        }
        
        return false;
    }
};
