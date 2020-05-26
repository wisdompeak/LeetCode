class Solution {
public:
    int calculate(string s) 
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

        vector<int>nums;

        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+' || s[i]=='-')
            {
                int j = i+1;
                while (j<s.size() && isdigit(s[j]))
                    j++;
                int num = stoi(s.substr(i+1,j-i-1));
                if (s[i]=='+') nums.push_back(num);
                else if (s[i]=='-') nums.push_back(-num);
                i = j-1;
            }
            else if (s[i]=='*' || s[i]=='/')
            {
                int j = i+1;
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
