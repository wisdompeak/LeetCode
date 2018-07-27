class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int>Stack;
        Stack.push(-1);
        int result = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')            
                Stack.push(i);                            
            else
            {
                Stack.pop();                    
                if (!Stack.empty())                                 
                    result = max(result, i-Stack.top());                
                else
                    Stack.push(i);
            }
        }
        return result;
    }
};
