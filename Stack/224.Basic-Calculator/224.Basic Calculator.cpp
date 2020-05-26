class Solution {
public:
    int calculate(string s) 
    {
        string S = "+";
        for (auto ch:s)
        {
            if (ch==' ') continue;
            S+=ch;
            if (ch=='(')
                S+="+";            
        }
        s = S;

        stack<int>nums;
        stack<int>signs;
        int sum = 0, sign;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+'||s[i]=='-')
            {
                sign = s[i]=='+'?1:-1;
            }
            else if (isdigit(s[i]))
            {
                int j = i;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                int num = stoi(s.substr(i,j-i));
                i = j-1;
                sum += num*sign;
            }
            else if (s[i]=='(')
            {
                nums.push(sum);
                signs.push(sign);
                sum = 0;
            }
            else if (s[i]==')')
            {                
                sum = nums.top() + signs.top() * sum;
                nums.pop();
                signs.pop();
            }
        }
        return sum;
        

    }
};
