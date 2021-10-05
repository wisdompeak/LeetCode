class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) 
    {        
        int count = 0;
        for (auto ch:s)
        {
            if (ch==letter)
                count++;
        }
        
        int k1 = count - repetition;
        int k0 = s.size() - k;
        
        stack<char>Stack;
        int count0 = 0;
        int count1 = 0;
            
        for (int i=0; i<s.size(); i++)
        {
            if (Stack.empty()||s[i]>=Stack.top())
            {
                Stack.push(s[i]);
            }
            else if (s[i]<Stack.top())
            {
                while (!Stack.empty() && s[i]<Stack.top() && ((Stack.top()!=letter || (Stack.top()==letter && count1<k1)) && count0<k0))
                {
                    if (Stack.top()==letter)
                        count1++;
                    count0++;
                    Stack.pop();                    
                }
                Stack.push(s[i]);
            }
        }
        
        
        string result;
        while (!Stack.empty())
        {
            result+=Stack.top();
            Stack.pop();
        }
                
        reverse(result.begin(),result.end());
                
        string ans;
        
        for (int i=result.size()-1; i>=0; i--)
        {
            if (count0 == k0)
                ans.push_back(result[i]);
            else
            {
                if (result[i]==letter)
                {
                    if (count1 == k1)
                        ans.push_back(result[i]);
                    else
                    {
                        count0++;
                        count1++;
                    }
                }
                else
                {
                    count0++;
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
