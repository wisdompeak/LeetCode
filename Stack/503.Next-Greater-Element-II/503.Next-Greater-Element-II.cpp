class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int N = nums.size();
        for (int i=0; i<N; i++)
            nums.push_back(nums[i]);
        
        stack<int>Stack;        
        vector<int>results(N,-1);
        
        for (int i=0; i<nums.size(); i++)
        {
            while (!Stack.empty() && nums[Stack.top()]<nums[i])
            {
                if (Stack.top() < N) 
                    results[Stack.top()] = nums[i];
                Stack.pop();
            }
            Stack.push(i);            
        }
        results.resize(N);
        return results;
    }
};
