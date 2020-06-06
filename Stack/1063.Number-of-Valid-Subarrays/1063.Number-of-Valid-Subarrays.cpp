class Solution {
public:
    int validSubarrays(vector<int>& nums) 
    {
        nums.push_back(INT_MIN);
        stack<int>Stack;
        int count = 0;
        for (int i=0; i<nums.size(); i++)
        {
            while (!Stack.empty() && nums[i]<nums[Stack.top()])
            {
                count += i-Stack.top();
                Stack.pop();
            }            
            Stack.push(i);
        }
        return count;        
    }
};
