class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int>Stack;
        vector<int>results;
        for (int i=temperatures.size()-1; i>=0; i--)
        {
            if (Stack.empty())
            {
                results.push_back(0);
                Stack.push(i);                
            }
            else if (temperatures[i]<temperatures[Stack.top()])
            {
                results.push_back(Stack.top()-i);
                Stack.push(i);
            }
            else 
            {
                while (!Stack.empty() && temperatures[i]>=temperatures[Stack.top()])
                    Stack.pop();
                if (Stack.empty())
                    results.push_back(0);
                else
                    results.push_back(Stack.top()-i);
                Stack.push(i);
            }
        }
        reverse(results.begin(),results.end());
        return results;
    }
};
