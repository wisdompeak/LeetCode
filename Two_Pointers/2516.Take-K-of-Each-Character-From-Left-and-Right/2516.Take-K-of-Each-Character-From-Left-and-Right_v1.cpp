class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='a') a++;
            else if (s[i]=='b') b++;
            else if (s[i]=='c') c++;
        }
        
        if (a<k || b<k || c<k) return -1;
        
        a = a-k;
        b = b-k;
        c = c-k;
        int left = 0, right = n;                        
        while (left < right)
        {
            int mid = right - (right-left)/2;
            if (isOK(s, mid, a,b,c))
                left = mid;
            else
                right = mid-1;
        }
        
        return n - left;        
    }
    
    bool isOK(string&s, int len, int A, int B, int C)
    {
        int a = 0,  b= 0, c = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='a') a++;
            else if (s[i]=='b') b++;
            else if (s[i]=='c') c++;
            
            if (i>=len)
            {
                if (s[i-len]=='a') a--;
                else if (s[i-len]=='b') b--;
                else if (s[i-len]=='c') c--;
            }
            
            if (i>=len-1)
            {
                if (a<=A && b<=B && c<=C)
                    return true;
            }
        }
        return false;
    }
};
