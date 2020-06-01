class Solution {
public:
    vector<string> braceExpansionII(string S) 
    {
        string expression;
        for (int i=0; i<S.size(); i++)
        {
            if (isalpha(S[i]))
            {
                expression.push_back('{');
                expression.push_back(S[i]);
                expression.push_back('}');
            }
            else
                expression.push_back(S[i]);                
        }
        
        stack<unordered_set<string>>stackStr;
        stack<int>stackOp;        
        unordered_set<string>cur;
        
        for (int i=0; i<expression.size(); i++)
        {
            if (expression[i]=='{')
            {
                stackStr.push(cur);                
                stackOp.push(0);
                cur = {};
            }
            else if (expression[i]==',')
            {
                stackStr.push(cur);                
                stackOp.push(1);
                cur = {};
            }
            else if (expression[i]=='}')
            {
                while (stackOp.top()==1)
                {                                        
                    cur = combine(stackStr.top(), cur);
                    stackStr.pop();
                    stackOp.pop();                    
                }                
                if (stackOp.top()==0)
                {
                    cur = crossProduct(stackStr.top(), cur);
                    stackStr.pop();
                    stackOp.pop();
                }                              
            }
            else
            {
                int j=i+1;
                while (j<expression.size() && isalpha(expression[j]))
                    j++;
                cur={expression.substr(i,j-i)};
                i = j-1;
            }
        }               
        
        vector<string>rets(cur.begin(), cur.end());
        sort(rets.begin(),rets.end());
        
        return rets;
    }

    unordered_set<string>combine(unordered_set<string>&s, unordered_set<string>&t)
    {
        unordered_set<string>ret;
        for (auto x:s)
            ret.insert(x);
        for (auto y:t)
            ret.insert(y);
        return ret;
    }
    
    unordered_set<string>crossProduct(unordered_set<string>&s, unordered_set<string>&t)
    {
        if (s.size()==0) s.insert("");
        if (t.size()==0) t.insert("");
        unordered_set<string>ret;
        for (auto x:s)
            for (auto y:t)
                ret.insert(x+y);
        return ret;
    }
};
