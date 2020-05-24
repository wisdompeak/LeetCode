class Solution {
public:
    int trap(vector<int>& height) 
    {
        stack<int>Stack;
        int ret = 0;

        for (int i=0; i<height.size(); i++)
        {
            while (!Stack.empty() && height[Stack.top()] < height[i])
            {                
                int base = height[Stack.top()];
                Stack.pop();
                if (Stack.empty()) continue;
                int h = min(height[Stack.top()], height[i]) - base;
                int w = i - Stack.top()-1;
                ret += h*w;                
            }
            Stack.push(i);
        }
        return ret;
    }
};
