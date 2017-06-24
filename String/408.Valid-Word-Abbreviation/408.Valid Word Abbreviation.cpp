class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int i=0;
        int j=0;
        
        while (j<abbr.size())
        {
            if (i>=word.size()) return false;
            
            if (abbr[j]=='0')
                return false;
            else if (abbr[j]>='0' && abbr[j]<='9')
            {
                int num=0;
                while (j<abbr.size() && abbr[j]>='0' && abbr[j]<='9')
                {
                    num=num*10+abbr[j]-'0';
                    j++;
                }
                i+=num;
            }
            else if (abbr[j]>='a' && abbr[j]<='z')
            {
                if (abbr[j]!=word[i])
                    return false;
                else
                {
                    i++;
                    j++;
                }
            }
        }
        
        if (i!=word.size()) 
            return false;
        else
            return true;
        
    }
};
