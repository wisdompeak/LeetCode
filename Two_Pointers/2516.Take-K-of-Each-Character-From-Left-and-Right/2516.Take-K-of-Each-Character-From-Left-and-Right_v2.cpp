class Solution {
public:
    int takeCharacters(string s, int k) 
    {

        int A = 0, B = 0, C = 0;
        for (auto ch: s)
        {
            if (ch=='a') A++;
            else if (ch=='b') B++;
            else if (ch=='c') C++;
        }
        if (A<k || B<k || C<k) return -1;

        A = A-k;
        B = B-k;
        C = C-k;

        int n = s.size();
        int j = 0;
        int a = 0, b = 0, c = 0;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            while (a<=A && b<=B && c<=C)
            {
                ret = max(ret, j-i);  // [i,j)
                if (j==n) break;
                if (s[j]=='a') a++;
                else if (s[j]=='b') b++;
                else if (s[j]=='c') c++;
                j++;
            }

            if (s[i]=='a') a--;
            else if (s[i]=='b') b--;
            else if (s[i]=='c') c--;
        }

        return n - ret;
    }   
};
