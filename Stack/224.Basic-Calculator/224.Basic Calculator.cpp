class Solution {
public:
    int calculate(string s) 
    {
        stack<int>nums;
        stack<int>sign;
        s.insert(s.begin(),'+');
        
        int curResult=0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                nums.push(curResult);
                curResult=0;
                sign.push(1);
            }
            else if (s[i]==')')
            {
                curResult*=sign.top();
                sign.pop();
                curResult+=nums.top();
                nums.pop();
            }
            else if (s[i]=='+')
                sign.push(1);
            else if (s[i]=='-')
                sign.push(-1);
            else if (s[i]>='0' && s[i]<='9')
            {
                int i0=i;
                while (i<s.size() && s[i]>='0' && s[i]<='9')
                    i++;
                int num = stoi(s.substr(i0,i-i0));
                curResult+=sign.top()*num;
                sign.pop();
                i--;
            }
        }
        
        return curResult;
        
    }
};
