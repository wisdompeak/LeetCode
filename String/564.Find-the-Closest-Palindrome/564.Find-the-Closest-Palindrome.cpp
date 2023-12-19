class Solution {
public:
    string nearestPalindromic(string n) 
    {
        string a = makeSmaller(n);
        string b = makeGreater(n);
        if (stoll(b)-stoll(n) >= stoll(n)-stoll(a))
            return a;
        else
            return b;
    }

    string makeSmaller(const string &n) 
    {
        const int m = n.length();
        string s = n;
        for (int i = 0, j = m - 1; i <= j;)
            s[j--] = s[i++];                    
        if (s < n) {
            return s;
        }

        int carry = 1;
        for (int i = (m - 1)/2; i >= 0; i--) 
        {
            int d = s[i]-'0'-carry;
            if (d>=0) 
            {
                s[i] = '0'+d;
                carry = 0;
            }
            else
            {
                s[i] = '9';
                carry = 1;
            }
            s[m-1-i] = s[i];
        }
        if (s[0]=='0' && m>1)
            return string(m - 1, '9');
        else
            return s;
    }

    string makeGreater(const string &n) 
    {
        const int m = n.length();
        string s = n;
        for (int i = 0, j = m - 1; i <= j;)
            s[j--] = s[i++];                    
        if (s > n) {
            return s;
        }

        int carry = 1;
        for (int i = (m - 1)/2; i >= 0; i--) 
        {
            int d = s[i]-'0'+carry;
            if (d<=9) 
            {
                s[i] = '0'+d;
                carry = 0;
            }
            else
            {
                s[i] = '0';
                carry = 1;
            }
            s[m-1-i] = s[i];
        }
        if (carry == 1)
        {
            s = string(m + 1, '0');
            s[0] = s.back() = '1';
            return s;
        }            
        else
            return s;
    }
};
