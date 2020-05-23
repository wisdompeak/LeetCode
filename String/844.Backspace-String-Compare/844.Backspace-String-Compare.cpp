class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        int i = convert(S);
        int j = convert(T);
        return S.substr(0,i)==T.substr(0,j);
    }

    int convert(string& str)
    {
        int i=0;
        for (int j=0; j<str.size(); j++)
        {
            if (str[j]!='#')
            {
                str[i] = str[j];
                i++;
            }
            else
            {
                i = max(0, i-1);
            }                
        }
        return i;
        
    }
};
