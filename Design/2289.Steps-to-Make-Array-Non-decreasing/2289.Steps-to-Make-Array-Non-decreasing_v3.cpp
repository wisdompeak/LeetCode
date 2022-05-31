class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>count(n);
        int ret = 0;
        stack<int>Stack;
        for (int i=n-1; i>=0; i--)
        {
            int temp = 0;
            while (!Stack.empty() && nums[i]>nums[Stack.top()])
            {                
                temp = max(temp+1, count[Stack.top()]);
                Stack.pop();
            }

            count[i] = temp;
            Stack.push(i);
            ret = max(ret, count[i]);
        }
        return ret;        
    }
};
