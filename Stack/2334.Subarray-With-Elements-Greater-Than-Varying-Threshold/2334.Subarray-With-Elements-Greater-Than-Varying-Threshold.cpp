class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) 
    {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);
        
        int n = nums.size();
        stack<int>stk;        
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && nums[i] < nums[stk.top()])            
            {
                int h = nums[stk.top()];
                stk.pop();
                int area = h*(i-stk.top()-1);
                if (area > threshold)
                    return i-stk.top()-1;
            }
            stk.push(i);
        }
        
        return -1;
        
    }
};
