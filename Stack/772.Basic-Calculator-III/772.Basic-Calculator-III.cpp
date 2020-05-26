class Solution {
public:
    int calculate(string s) 
    {
        stack<string>Stack;
        string curStr;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                Stack.push(curStr);
                curStr = "";
            }
            else if (s[i]==')')
            {                
                int curRes = eval(curStr);
                curStr = Stack.top() + to_string(curRes);
                Stack.pop();                
            }
            else
                curStr.push_back(s[i]);
        }
        return eval(curStr);        
    }
    
    int eval(string s)
    {
        string S = "+";
        for (auto ch:s)
        {
            if (ch==' ') continue;
            S.push_back(ch);
            if (ch=='(')
                S+="+";
        }
        s = S;
        
        vector<long>nums;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+' || s[i]=='-')
            {
                int j = i+1;
                if (s[j]=='+' || s[j]=='-') j++;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                long num = stol(s.substr(i+1,j-i-1));
                if (s[i]=='+') nums.push_back(num);
                else if (s[i]=='-') nums.push_back(-num);
                i = j-1;
            }
            else if (s[i]=='*' || s[i]=='/')
            {
                int j = i+1;
                if (s[j]=='+' || s[j]=='-') j++;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                int num = stoi(s.substr(i+1,j-i-1));                
                if (s[i]=='*') nums.back() *= num;
                else if (s[i]=='/') nums.back() /= num;
                i = j-1;
            }
        }

        int ret = 0;
        for (int i=0; i<nums.size(); i++)
            ret+=nums[i];
        return ret;
    }
    
    
};
