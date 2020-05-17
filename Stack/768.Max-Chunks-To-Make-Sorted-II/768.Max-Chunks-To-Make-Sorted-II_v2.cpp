class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        stack<int>Stack;
        int curMax;
        for (auto x: arr)
        {
            if (Stack.empty()||Stack.top()<=x)
            {
                Stack.push(x);
                curMax = x;
            }                
            else
            {
                while (!Stack.empty() && Stack.top()>x)
                    Stack.pop();
                Stack.push(curMax);
            }
        }
        return Stack.size();
    }
};
