class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int j = 0;
        int count1 = 0, count2 = 0, count3 = 0;
        int ret = 0;
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && (count1 * count2 * count3 == 0))
            {
                if (s[j]=='a') count1++;
                else if (s[j]=='b') count2++;
                else if (s[j]=='c') count3++;
                j++;
            }
            if (count1 * count2 * count3 > 0)
                ret += s.size()-j+1;
            
            if (s[i]=='a') count1--;
            else if (s[i]=='b') count2--;
            else if (s[i]=='c') count3--;
        }
        
        return ret;
    }
};
