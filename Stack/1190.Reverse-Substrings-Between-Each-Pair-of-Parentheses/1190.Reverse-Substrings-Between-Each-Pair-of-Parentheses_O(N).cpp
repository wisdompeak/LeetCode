class Solution {
public:
    string reverseParentheses(string s) 
    {
        int n = s.size();
        vector<int>pair(n,-1);
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='(')
                Stack.push(i);
            else if (s[i]==')')
            {
                int j = Stack.top();
                pair[i]=j;
                pair[j]=i;
                Stack.pop();
            }
        }

        int i = 0;
        int d = 1;
        string ret;
        while (i<n)
        {
            if (isalpha(s[i]))
                ret.push_back(s[i]);
            else
            {
                i = pair[i];
                d = -d;
            }
            i+=d;            
        }
        return ret;

    }
};
