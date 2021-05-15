class Solution {
public:
    bool isNumber(string s) 
    {
        // Filter out white spaces
        while (s.size()>0 && s.back()==' ') s.pop_back();
        while (s.size()>0 && s[0]==' ') s.erase(s.begin());
        if (s=="") return false;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='E')
                s[i] = 'e';
        }

        int countE = 0;     
        string t;   
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+'||s[i]=='-') // If it is a sign, it has to be at the head or right after "e"
            {
                if (!(i==0 || (i>0 && s[i-1]=='e'))) 
                    return false;
            }
            else
            {
                if (s[i]=='e') countE++;
                t.push_back(s[i]);
            } 
        }        
        if (countE==0) return isOK(t,1);
        if (countE>1) return false;

        int k = 0;
        while (t[k]!='e') k++;
        return isOK(t.substr(0,k),1) && isOK(t.substr(k+1),0);
    }

    bool isOK(string s, int k)
    {
        if (s=="" || s==".") return false;
        int countDot = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='.')
                countDot++;            
            else if (!isdigit(s[i]))
                return false;
        }
        return countDot<=k;
    }
};
