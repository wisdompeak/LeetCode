class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char>Stack;
        int count=0;
            
        for (int i=0; i<num.size(); i++)
        {
            if (Stack.empty()||num[i]>=Stack.top())
            {
                Stack.push(num[i]);
            }
            else if (num[i]<Stack.top())
            {
                while (!Stack.empty() && num[i]<Stack.top() && count<k)
                {
                    Stack.pop();
                    count++;
                }
                Stack.push(num[i]);
            }
        }
        
        for (int i=count+1; i<=k; i++)
            Stack.pop();
        
        string result;
        while (!Stack.empty())
        {
            result+=Stack.top();
            Stack.pop();
        }
        while (result.size()>0 && result.back()=='0')
            result.pop_back();
                
        reverse(result.begin(),result.end());
        if (result=="")
            result="0";
        
        return result;
            
    }
};
