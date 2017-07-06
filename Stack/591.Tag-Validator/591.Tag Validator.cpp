class Solution {
public:
    bool isValid(string code) 
    {
        stack<string>TagStack;
        int i=0;
        bool cdata_flag=0;
        bool ever=0;

        while (i<code.size())
        {
            if (cdata_flag==0 && i+9<=code.size() && code.substr(i,9)=="<![CDATA[")
            {
                cdata_flag=1;
                i+=9;
                continue;
            }
            
            if (cdata_flag==1)
            {
                if (i+3<=code.size() && code.substr(i,3)=="]]>")
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
                while (i<code.size() && code[i]!='>') i++;
                if (i==code.size()) return false;
                string TagName=code.substr(i0,i-i0);
                
                if (validTagName(TagName)==false)
                    return false;
                else if (TagStack.empty() && i0-1!=0) // must start with a tag
                    return false;
                else
                {
                    TagStack.push(TagName);
                    ever=1; 
                }
                i++;
                continue;
            }
            
            if (code[i]=='<' && i+1<code.size() && code[i+1]=='/')
            {
                i+=2;
                int i0=i;
                while (i<code.size() && code[i]!='>') i++;
                if (i==code.size()) return false;
                string TagName=code.substr(i0,i-i0);
                
                if (TagStack.empty() || TagStack.top()!=TagName)
                    return false;
                else if (TagStack.size()==1 && i<code.size()-1)  // must end with a tag
                    return false;
                else
                    TagStack.pop();
                i++;
                continue;
            }
            
            i++;
        }
        
        if (TagStack.empty() && ever==1)
            return true;
        else
            return false;
        
    }
    
        bool validTagName(string t)
        {
            if (t=="") return false;
            if (t.size()>9) return false;
            for (int i=0; i<t.size(); i++)
            {
                if (t[i]<'A' || t[i]>'Z')
                    return false;
            }
            return true;
        }    
};
