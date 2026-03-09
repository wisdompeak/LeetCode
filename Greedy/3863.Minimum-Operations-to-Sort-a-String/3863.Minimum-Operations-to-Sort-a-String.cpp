class Solution {
public:
    int minOperations(string s) {        
        int n = s.size();
        if (n==2 && s[0]>s[1]) return -1;

        string t = s;
        sort(t.begin(), t.end());
        if (t==s) return 0;

        {            
            if (s[0]==t[0]) return 1;
            if (s.back()==t.back()) return 1;
        }
        {            
            if (s[0]==t.back() && s[0]!=t[n-2] && s.back()==t[0] && s.back()!=t[1])
                return 3;
        }
        return 2;
    }
};
