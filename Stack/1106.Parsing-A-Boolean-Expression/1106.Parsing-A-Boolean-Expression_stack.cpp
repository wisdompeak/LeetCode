class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char>stackOp;
        stack<vector<int>>stackVal;
        vector<int>curVals;
        int ret;

        for (int i=0; i<expression.size(); i++)
        {
            if (expression[i]=='!' || expression[i]=='&' || expression[i]=='|')
            {
                stackOp.push(expression[i]);
                stackVal.push(curVals);
                curVals.clear();
                i++;
            }
            else if (expression[i]==')')
            {
                ret = eval(stackOp.top(), curVals);
                stackOp.pop();
                curVals = stackVal.top();
                curVals.push_back(ret);
                stackVal.pop();
            }
            else if (expression[i]=='t' || expression[i]=='f' )
            {
                curVals.push_back(expression[i]=='t');
            }
        }

        return ret;
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
