class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        bool ret = helper(expression, 0, expression.size()-1);
        return ret;
    }
    
    bool helper(string &s, int a, int b)
    {
        if (a==b)
        {
            return (s[a]=='t') ? 1:0;
        }
        
        vector<bool>vals;
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
            else if (s[i]==',')
                continue;
            else
            {
                if (s[i]=='t')
                    vals.push_back(1);
                else if (s[i]=='f')
                    vals.push_back(0);
            }
            
        }
        if (s[a]=='!')
            return !vals[0];
        else if (s[a]=='&')
        {
            int ret = 1;
            for (auto x:vals)
                ret = ret && x;
            return ret;
        }
        else if (s[a]=='|')
        {
            int ret = 0;
            for (auto x:vals)
                ret = ret || x;
            return ret;
        }
        return {};
            
    }
};
