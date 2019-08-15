class Solution {
public:
    int calculate(string s) 
    {
        string S = "+";        
        
        for (auto ch : s)
        {
            if (ch==' ') continue;
            S.push_back(ch);
            if (ch=='(')
                S.push_back('+');
        }
        s = S;
        // cout<<s<<endl;
        
        stack<int>nums;
        stack<int>signs;
        int sum = 0;
        int sign = 0;
        
        for (int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if (ch=='+' || ch=='-')
            {
                sign = ch=='+'? 1:-1;
            }
            else if (isdigit(ch))
            {
                int i0 = i;
                while (i<s.size() && isdigit(s[i]))
                    i++;
                int num = stoi(s.substr(i0,i-i0));
                sum += sign*num;
                i--;
            }
            else if (ch=='(')
            {
                nums.push(sum);
                signs.push(sign);
                sum = 0;
            }
            else if (ch==')')
            {
                sum = signs.top()*sum;
                signs.pop();
                sum = nums.top() + sum;
                nums.pop();
            }
        }
        return sum;        
    }
};
