class Solution {
public:
    bool isValid(string code) 
    {
        stack<string>Stack;
        int i=0;
        bool cdata_flag=0;
        int ever=0;
        
        while (i<code.size())
        {
            cout<<code[i];
            
            if (cdata_flag==0 && i+9<code.size() && code.substr(i,9)=="<![CDATA[")
            {
                cdata_flag=1;
                i+=9;
                continue;
            }
            
            if (cdata_flag==1)
            {
                if  (i+3<code.size() && code.substr(i,3)=="]]>")
                {
                    cdata_flag=0;
                    i+=3;
                    continue;
                }
                else
                {
                    i++;
                    continue;
                }                
            }
            
            if (code[i]=='<' && i+1<code.size() && code[i+1]!='/')
            {
                i++;
                int i0=i;
                while (code[i]!='>') i++;
                if (i==code.size()) return false;

                string tag = code.substr(i0,i-i0);                
                if (validTagName(tag)==false)
                    return false;
                else if (Stack.empty() && i0!=1)
                    return false;
                else
                {
                    Stack.push(tag);
                    ever=1;
                }
                i++;                    
                continue;
            }
            
            if (code[i]=='<' && i+1<code.size() && code[i+1]=='/')
            {
                i+=2;
                int i0=i;
                while (code[i]!='>') i++;
                if (i==code.size()) return false;

                string tag = code.substr(i0,i-i0);                
                if (Stack.empty() || Stack.top()!=tag)
                    return false;
                else if (Stack.size()==1 && i!=code.size()-1)
                    return false;
                else
                    Stack.pop();    
                i++;
                continue;
            }
            
            i++;
            
                        
        }
        
        if (Stack.empty() && ever==1)
            return true;
        else
            return false;        

    }
    
        bool validTagName(string tag)
        {
            if (tag.size()==0 || tag.size()>9) return false;
            for (int i=0; i<tag.size(); i++)
            {
                if (tag[i]>'Z' || tag[i]<'A') return false;
            }
            return true;                
        }    
};
