class Solution {
public:
    int scoreOfParentheses(string S) 
    {
        stack<int>Stack;
        int cur = 0;
        for (auto ch:S)
        {
            if (ch==')')
            {
                if (cur==0)
                    cur = 1;
                else
                    cur = cur*2;
                cur = Stack.top()+cur;
                Stack.pop();
            }
            else
            {
                Stack.push(cur);
                cur = 0;
            }
        }
        return cur;

    }
};
