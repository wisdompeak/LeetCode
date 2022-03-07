class Solution {
public:
    int minMovesToMakePalindrome(string s) 
    {
        int n = s.size();
        int ret = 0;
        int c = 0;
        
        for (int i=0; i<n/2; i++)
        {            
            int j = n-1-c;
            while (s[j]!=s[i]) j--;
            if (i==j)
            {
                int k = n/2-j;
                ret += k;
            }
            else
            {
                int k = n-1-c-j;
                ret += k;
                while (k--)
                {
                    swap(s[j], s[j+1]);
                    j++;
                }         
                c++;
            }
        }
        
        return ret;
    }
};
