class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        stack<char>Stack;
        vector<int>Left(256,0);
        for (int i=0; i<s.size(); i++)
            Left[s[i]]++;
        vector<int>used(256,0);
        
        for (int i=0; i<s.size(); i++)
        {
            if (used[s[i]]==1)
            {
                
            }
            else if (Stack.empty() || s[i]>Stack.top())
            {
                Stack.push(s[i]);
                used[s[i]]=1;
            }
            else
            {
                while (!Stack.empty() && Stack.top()>=s[i] && Left[Stack.top()]>0)
                {
                    used[Stack.top()]=0;
                    Stack.pop();
                }
                Stack.push(s[i]);
                used[s[i]]=1;
            }
            Left[s[i]]--;
        }
        
        string result;
        while (!Stack.empty())
        {
            result+=Stack.top();
            Stack.pop();
        }
        reverse(result.begin(),result.end());
        
        return result;
    }
};
