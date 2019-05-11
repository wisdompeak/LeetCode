class Solution {
public:
    bool isValid(string code) 
    {
        stack<string>Stack;
        
        int i=0;
        bool ever = 0;
        
        while (i<code.size())
        {
            if (i+8<code.size() && code.substr(i,9)=="<![CDATA[")
            {
                i+=9;
                int i0=i;
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
                if (i==code.size()) return false;
                string tagname = code.substr(i0,i-i0);
                if (Stack.empty() || Stack.top()!=tagname)
                    return false;
                Stack.pop();
                i++; 
                if (Stack.empty() && i!=code.size()) return false;                             
            }
            
            else if (code[i]=='<')
            {
                i++;
                int i0=i;
                while (i<code.size() && code[i]!='>')
                    i++;
                if (i==code.size()) return false;
                string tagname = code.substr(i0,i-i0);
                if (!isValidTag(tagname)) return false;                
                if (ever==false && i0!=1) return false;
                ever = true;                
                Stack.push(tagname);
                i++;
            }
            
            else
                i++;
        }
        
        if (!Stack.empty()) return false;
        if (ever==0) return false;
        
        return true;
    }
    
    bool isValidTag(string tagname)
    {
        if (tagname.size()<1 || tagname.size()>9) return false;
        for (auto ch:tagname)
            if (ch<'A'|| ch>'Z') return false;
        return true;
    }
    
};
