class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int>Stack;
        int j = 0;
        for (int i=0; i<pushed.size(); i++)
        {
            Stack.push(pushed[i]);
            while (i<popped.size() && !Stack.empty() && Stack.top()==popped[j])
            {
                Stack.pop();
                j++;
            }
        }
        return j==popped.size();
    }
};
