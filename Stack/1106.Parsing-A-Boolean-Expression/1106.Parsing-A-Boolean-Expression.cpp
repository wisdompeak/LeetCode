class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        auto x =  dfs(expression,0,expression.size()-1);
        cout<<x.size()<<endl;
        return x[0]=='t'?true:false;
    }
    
    vector<char> dfs(string &expression, int a, int b)
    {
        if (a>b)
            return {};
        
        vector<char>Stack;
        char cur;
        
        for (int i=a; i<=b; i++)
        {
            if (expression[i]=='!' || expression[i]=='&' || expression[i]=='|')
            {
                int level = 1;
                int j = i+2;
                while (j<b && level>0)
                {
                    level += (expression[j]=='(');
                    level -= (expression[j]==')');
                    if (level==0)
                        break;
                    else
                        j++;
                }
                auto next = dfs(expression,i+2,j-1); 
                cur = eval(expression[i],next);
                i = j;                
            }
            else if (expression[i]==',')
            {
                Stack.push_back(cur);
            }
            else 
                cur = expression[i];                
        }
        Stack.push_back(cur);

        return Stack;
    }
    
    char eval(char oper, vector<char>&chars)
    {
        vector<int>nums(chars.size());
        for (int i=0; i<nums.size(); i++)
        {
            if (chars[i]=='t')
                nums[i]=1;
            else
                nums[i]=0;                
        }
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
        return result==1?'t':'f';
    }
};
