class Solution {
public:
    bool isNumber(string s) 
    {
        // Filter out white spaces
        while (s.size()>0 && s.back()==' ') s.pop_back();
        while (s.size()>0 && s[0]==' ') s.erase(s.begin());
        if (s=="") return false;
        
        // Filter out signs. Leave only dot, e, or digits.
        string t;        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='+'||s[i]=='-') // If it is a sign, it has to be at the head or right after "e"
            {
                if (!(i==0 || (i>0 && s[i-1]=='e'))) 
                    return false;
            }
            else if (s[i]!='e' && s[i]!='.' && !isdigit(s[i]) ) // If illeagle char
                return false;
            else
                t.push_back(s[i]);
        }
        
        if (t=="." || t=="e") return false;
        
        int countE = 0;
        int countDot = 0;
        for (int i=0; i<t.size(); i++)
        {
            if (t[i]=='e') // Locate "e". The substrings before "e" and after "e" must be isNumber.
            {
                if (countE!=0) return false;
                if (i==0 || i==t.size()-1) return false;
                if (!isNumber(t.substr(0,i))) return false;
                countE++;
                
            }
            else if (t[i]=='.')
            {
                if (countDot!=0) return false; // Never two dots. And the only dot must appear before "e".
                if (countE!=0) return false;   // Never two "e"s
                countDot++;
            }
        }
            
        return true;
    }
};
