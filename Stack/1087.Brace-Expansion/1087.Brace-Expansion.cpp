class Solution {
public:
    vector<string> expand(string S) 
    {
        string s;
        for (int i=0; i<S.size(); i++)
        {
            if (isalpha(S[i]))
            {
                s.push_back('{');
                s.push_back(S[i]);
                s.push_back('}');
            }
            else
                s.push_back(S[i]);                
        }        
        S = "{"+s+"}";
        cout<<S<<endl;
        
        stack<vector<string>>stackStr;
        stack<int>stackOp;
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
                    stackOp.pop();
                    stackStr.pop();
                }                    
                if (stackOp.top()==0)
                {
                    cur = crossProduct(stackStr.top(), cur);
                    stackOp.pop();
                    stackStr.pop();
                }
            }
        }
        sort(cur.begin(), cur.end());
        return cur;        
    }
    
    vector<string> crossProduct(vector<string>&s, vector<string>&t)
    {
        vector<string>ret;
        if (s.size()==0) s.push_back("");
        if (t.size()==0) t.push_back("");
        for (int i=0; i<s.size(); i++)
            for (int j=0; j<t.size(); j++)
                ret.push_back(s[i]+t[j]);
        return ret;        
    }
    
    vector<string> combine(vector<string>&s, vector<string>&t)
    {
        vector<string>ret;        
        for (int i=0; i<s.size(); i++)
            ret.push_back(s[i]);
        for (int i=0; i<t.size(); i++)
            ret.push_back(t[i]);        
        return ret;        
    }    
};

