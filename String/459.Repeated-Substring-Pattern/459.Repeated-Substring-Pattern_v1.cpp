class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        for (int i=s.size()/2; i>=1; i--)
        {
            if (s.size()%i!=0) continue;
            
            int flag=1;
            string t = s.substr(0,i);
            int j=i;
            while (j<s.size())
            {
                if (t!=s.substr(j,i))
                {
                    flag=0;
                    break;
                }
                j+=i;
            }
            
            if (flag==1) return true;
        }
        
        return false;
        
    }
};
