class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<int>Stack;
        int count=0;
        
        for (int i=0; i<num.size(); i++)
        {
            if (count==k)
            {
                Stack.push(num[i]-'0');
                continue;
            }
            
            if (Stack.empty() || num[i]-'0'>Stack.top())
            {
                Stack.push(num[i]-'0');
            }
            else
            {
                while (count<k && !Stack.empty() && Stack.top()>num[i]-'0')
                {
                    Stack.pop();
                    count++;
                }
                Stack.push(num[i]-'0');
            }
        }
        
        while (count<k)
        {
            Stack.pop();
            count++;
        }
        
        string result;
        while (!Stack.empty())
        {
            result+=('0'+Stack.top());
            Stack.pop();
        }
        
        int i=result.size()-1;
        while (result.back()=='0')
            result.pop_back();
        reverse(result.begin(),result.end());
        
        if (result=="") result="0";
        
        return result;
    }
};
