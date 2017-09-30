class Solution {
public:
    bool checkValidString(string s) 
    {
        int lower=0;
        int upper=0;
        
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
            {
                lower++;
                upper++;
            }
            else if (s[i]=='*')
            {
                lower--;
                upper++;
            }
            else if (s[i]==')')
            {
                lower--;
                upper--;
            }
            
            if (lower<0) lower=0;
            
            if (upper<0) return false;                        
        }
        
        return (lower==0);
    }
};
