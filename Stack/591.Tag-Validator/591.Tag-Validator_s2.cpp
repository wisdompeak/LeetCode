class Solution {
public:
    bool isValid(string code) 
    {
        int i=0;
        stack<string>Stack;
        bool head=0;
        
        while (i<code.size())        
        {
            if (i+8<code.size() && code.substr(i,9)=="<![CDATA[")
            {
                i+=9;
                while (i+2<code.size() && code.substr(i,3)!="]]>")
                    i++;
                if (i+2==code.size()) return false;
                i+=3;
            }         
            else if (i+1<code.size() && code.substr(i,2)=="</")
            {
                i+=2;
                int i0=i;
                while (i<code.size() && code[i]!='>')
                    i++;
                if (i==code.size() || code[i]!='>')
                    return false;
                string tagName=code.substr(i0,i-i0);
                if (validTag(tagName)==false)
                    return false;
                if (Stack.empty() || Stack.top()!=tagName)
                    return false;
                Stack.pop();
                if (Stack.empty() && i!=code.size()-1)
                    return false;
                i++;
            }
            else if (code[i]=='<')
            {
                head=1;
                i++;
                int i0=i;
                while (i<code.size() && code[i]!='>')
                    i++;
                if (i==code.size() || code[i]!='>')
                    return false;
                string tagName=code.substr(i0,i-i0);
                if (validTag(tagName)==false)
                    return false;
                if (Stack.empty() && i0!=1)
                    return false;
                Stack.push(tagName);
                i++;
            }               
            else
                i++;
        }
        
        if (head==0 || !Stack.empty())
            return false;
        else
            return true;
    }
    
    bool validTag(string tag)
    {
        if (tag.size()==0 || tag.size()>9) return false;
        
        for (int i=0; i<tag.size(); i++)
        {
            if (tag[i]>'Z' || tag[i]<'A') return false;
        }
        
        return true;         
    }
};
