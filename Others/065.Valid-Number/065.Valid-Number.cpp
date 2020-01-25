class Solution {
public:
    bool isNumber(string s) 
    {
        while (s.size()>0 && s.back()==' ') s.pop_back();
        while (s.size()>0 && s[0]==' ') s.erase(s.begin());
        if (s=="") return false;
        
        string t;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+'||s[i]=='-')
            {
                if (!(i==0 || (i>0 && s[i-1]=='e'))) 
                    return false;
            }
            else if (s[i]!='e' && s[i]!='.' && !isdigit(s[i]) )
                return false;
            else
                t.push_back(s[i]);
        }
        
        if (t=="." || t=="e") return false;
        
        int countE = 0;
        int countDot = 0;
        for (int i=0; i<t.size(); i++)
        {
            if (t[i]=='e')
            {
                if (countE!=0) return false;
                if (i==0 || i==t.size()-1) return false;
                if (!isNumber(t.substr(0,i))) return false;
                countE++;
                
            }
            else if (t[i]=='.')
            {
                if (countDot!=0) return false;
                if (countE!=0) return false;
                countDot++;
            }
        }
            
        return true;
    }
};
