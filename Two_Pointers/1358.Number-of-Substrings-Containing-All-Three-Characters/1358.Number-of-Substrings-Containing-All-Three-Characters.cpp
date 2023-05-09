class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int j = 0;
        int count1 = 0, count2 = 0, count3 = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            while (!(count1&&count2&&count3) && j<s.size())
            {
                if (s[j]=='a') count1++;
                else if (s[j]=='b') count2++;
                else if (s[j]=='c') count3++;
                j++;
            }
            if (count1&&count2&&count3)
                ret += s.size()-j+1;
            
            if (s[i]=='a') count1--;
            else if (s[i]=='b') count2--;
            else if (s[i]=='c') count3--;
        }
        
        return ret;
    }
};
