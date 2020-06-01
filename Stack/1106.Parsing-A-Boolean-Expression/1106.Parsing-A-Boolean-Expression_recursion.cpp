class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        bool ret = helper(expression, 0, expression.size()-1);
        return ret;
    }
    
    bool helper(string &s, int a, int b)
    {
        vector<int>vals;
        for (int i=a+2; i<=b-1; i++)
        {
            if (s[i]=='&' || s[i]=='|' || s[i]=='!')
            {                
                int level = 1;
                int j = i+2;
                while (j<=b-1 && level>0)
                {
                    level += (s[j]=='(');
                    level -= (s[j]==')');
                    if (level==0)
                        break;
                    else
                        j++;
                }
                vals.push_back(helper(s, i, j));
                i = j;
            }
            else if (s[i]=='t' || s[i]=='f')
            {
                vals.push_back(s[i]=='t');
            }            
        }
        return eval(s[a], vals);        
    }

    int eval(char oper, vector<int>&nums)
    {        
        int result;
        if (oper=='!')
            result = !nums[0];
        else if (oper=='&')
        {
            result = 1;
            for (int i=0; i<nums.size(); i++)
                result = result&nums[i];
        }
        else if (oper=='|')
        {
            result = 0;
            for (int i=0; i<nums.size(); i++)
                result = result|nums[i];
        }

        return result;
    }
};
