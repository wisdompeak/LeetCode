class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int>Stack;
        vector<int>rets(n);
        
        for (int i=n-1; i>=0; i--)
        {
            int count = 0;
            while (!Stack.empty() && heights[i] > heights[Stack.top()])
            {
                count++;
                Stack.pop();
            }
            if (!Stack.empty())
                count++;
            rets[i] = count;
            Stack.push(i);
        }

        return rets;

    }
};
