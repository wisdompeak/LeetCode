class Solution {
public:
    vector<string> expand(string S) 
    {
        string s;
        for (auto ch: S)
        {
            if (isalpha(ch))
            {
                s.push_back('{');
                s.push_back(ch);
                s.push_back('}');
            }
            else
                s.push_back(ch);
        }
        S = s;
        
        stack<int>stackOp;
        stack<vector<string>>stackStr;
        vector<string>cur;
            
        for (int i=0; i<S.size(); i++)
        {
            if (S[i]=='{')
            {
                stackStr.push(cur);
                stackOp.push(0);
                cur.clear();
            }
            else if (S[i]==',')
            {
                stackStr.push(cur);
                stackOp.push(1);
                cur.clear();
            }
            else if (isalpha(S[i]))
            {
                string temp;
                temp.push_back(S[i]);
                cur.push_back(temp);
            }
            else if (S[i]=='}')
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
        }
        
        sort(cur.begin(), cur.end());
        return cur;        
    }
    
    vector<string>combine(vector<string>&s, vector<string>&t)
    {
        vector<string>ret;
        for (int i=0; i<s.size(); i++)
            ret.push_back(s[i]);
        for (int i=0; i<t.size(); i++)
            ret.push_back(t[i]);
        return ret;
    }
    
    vector<string>crossProduct(vector<string>&s, vector<string>&t)
    {
        if (s.size()==0) s.push_back("");
        if (t.size()==0) t.push_back("");
        vector<string>ret;
        for (int i=0; i<s.size(); i++)
            for (int j=0; j<t.size(); j++)
            {
                ret.push_back(s[i]+t[j]);
            }
        return ret;
    }
};




