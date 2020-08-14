class Solution {
public:
    int minInsertions(string s) 
    {
        int count = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
                count++;
            else
            {
                if (i+1<s.size() && s[i+1]==')')
                {
                    count--;
                    i++;
                }
                else
                {
                    count--;
                    ret++;
                }
            }
            if (count<0)
            {
                ret++;
                count=0;
            }
        }
        return ret + count*2;
    }
};
