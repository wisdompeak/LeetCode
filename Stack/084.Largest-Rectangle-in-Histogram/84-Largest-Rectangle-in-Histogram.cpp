class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        stack<int>Stack;
        int result = 0;
        for (int i=0; i<heights.size(); i++)
        {
            while (!Stack.empty() && heights[Stack.top()] > heights[i])
            {
                int H = heights[Stack.top()];
                Stack.pop();                    
                result = max(result, H*(i-Stack.top()-1));                    
            }
            Stack.push(i);            
        }
        return result;        
    }
};
