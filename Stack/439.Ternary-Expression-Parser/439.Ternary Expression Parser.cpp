class Solution {
public:
    string parseTernary(string expression) 
    {
        stack<string>Stack;
        string curRes;
        
        for (int i=0; i<expression.size(); i++)
        {
            if (i+1<expression.size() && expression[i+1]=='?')
            {
                Stack.push(curRes);
                curRes=expression[i];
            }                            
            else
            {
                curRes+=expression[i];
                while (curRes.size()==5)
                {
                    curRes=evaluate(curRes);
                    curRes=Stack.top()+curRes;
                    Stack.pop();
                }
            }
        }
        
        return curRes;
    }
    
    string evaluate(string s)
    {
        string result;
        if (s[0]=='T')  
            result=s[2];
        else    
            result=s[4];
        return result;
    }
};
