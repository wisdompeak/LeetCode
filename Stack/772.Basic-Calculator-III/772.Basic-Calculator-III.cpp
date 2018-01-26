class Solution {
public:
    int readNext(string s, int& i)
    {
        int i0=i;
        if (s[i]=='+' || s[i]=='-')
            i++;        
        while (i<s.size() && isdigit(s[i]))
            i++;
        int res = stol(s.substr(i0,i-i0));
        i--;
        return res;
    }
    
    int calculateClip(string ss)
    {        
        vector<int>q;        
        for (int i=0; i<ss.size(); i++)
        {
            if (ss[i]=='+' || ss[i]=='-')
            {                
                q.push_back(readNext(ss,i));
                i--;
            }
            else if (ss[i]=='*')
            {
                i++;
                int num = readNext(ss,i);
                q.back()*=num;
                i--;
            }
            else if (ss[i]=='/')
            {
                i++;
                int num = readNext(ss,i);
                q.back()/=num;
                i--;
            }
        }
        int sum = 0;
        for (int i=0; i<q.size(); i++)
            sum+=q[i];
        return sum;
    }
    
    int calculate(string s) 
    {
        string S="+";
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]!=' ') 
                S+=s[i];
            if (s[i]=='(')
                S+='+';
        }            
        //cout<<S<<endl;        
        
        stack<string>Stack;
        string temp;
        for (int i=0; i<S.size(); i++)
        {
            if (S[i]=='(')
            {
                Stack.push(temp);
                temp.clear();                
            }
            else if (S[i]==')')
            {
                int num = calculateClip(temp);
                string ss = to_string(num);
                string tt = Stack.top();
                Stack.pop();
                if (tt.size()>0 && tt.back()=='+' && ss[0]=='-')
                {
                    tt.pop_back();
                    temp = tt+ss;
                }
                else if (tt.size()>0 && tt.back()=='-' && ss[0]=='-')
                {                    
                    tt.pop_back();
                    temp = tt+"+"+ss.substr(1);
                }
                else                                                     
                    temp = tt+ss;                                
            }
            else
                temp+=S[i];            
        }
        
        return calculateClip(temp);
    }
};
