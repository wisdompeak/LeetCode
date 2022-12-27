class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        if (k==0) return 0;

        int a = 0, b = 0, c = 0;
        for (auto ch: s)
        {
            if (ch=='a') a++;
            else if (ch=='b') b++;
            else if (ch=='c') c++;
        }
        if (a<k || b<k || c<k) return -1;
                
        int n = s.size();
        int ret = n;
        int j = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='a') a--;
            else if (s[i]=='b') b--;
            else if (s[i]=='c') c--;

            while (j<n && (a<k || b<k || c<k))
            {                
                if (s[j]=='a') a++;
                else if (s[j]=='b') b++;
                else if (s[j]=='c') c++;
                j++;
            }
            if (a>=k && b>=k && c>=k)
                ret = min(ret, n-1-i+j);
        }

        return ret;
    }   
};
