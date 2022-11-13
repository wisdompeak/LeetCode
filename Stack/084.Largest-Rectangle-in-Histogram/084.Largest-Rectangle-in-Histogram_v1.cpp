class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();        
        stack<int>stk;        
        vector<int>nextSmaller(n, n);
        for (int i=0; i<heights.size(); i++)
        {
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {
                nextSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);                
        }
        
        while (!stk.empty()) stk.pop();
        vector<int>prevSmaller(n, -1);
        for (int i=heights.size()-1; i>=0; i--)
        {
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {   
                prevSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);              
        }
                
        int ret = 0;
        for (int i=0; i<n; i++)
            ret = max(ret, heights[i]*(nextSmaller[i] - prevSmaller[i] - 1));
        
        return ret;          
    }
};
