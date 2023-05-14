class Solution {
public:
    string smallestBeautifulString(string s, int k) 
    {
        string temp = s;
        int n = s.size();
        int flag = 0;
        for (int i=n-1; i>=0; i--)
        {
            for (char ch=s[i]+1; ch<'a'+k; ch++)
            {
                if (!checkOK(s, i, ch)) continue;
                flag = 1;
                s[i] = ch;
                for (int j=i+1; j<n; j++)
                {                    
                    for (char c='a'; c<'a'+k; c++)
                    {
                        if (checkOK(s, j, c))
                        {
                            s[j] = c;
                            break;                            
                        }
                    }                    
                }    
                break;            
            }     
            if (flag) break;    
        }

        if (s==temp) return "";
        else return s;        
    }

    bool checkOK(string&s, int i, char ch)
    {
        if (i-1>=0 && s[i-1]==ch) return false;
        if (i-2>=0 && s[i-2]==ch) return false;
        return true;
    }
};
