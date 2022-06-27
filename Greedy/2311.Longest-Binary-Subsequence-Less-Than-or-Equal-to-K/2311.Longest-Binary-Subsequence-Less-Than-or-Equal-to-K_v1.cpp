class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        string t;
        while (k>0)
        {
            if (k%2==0)
                t.push_back('0');
            else
                t.push_back('1');
            k/=2;
        }
        reverse(t.begin(), t.end());
        
        int m = s.size();
        int n = t.size();
        
        if (m<n) return m;
        
        int ret = countZeros(s, m-n+1) + n-1;  
        
        for (int i=m-1; i>=0; i--)
        {
            if (check(s,i,t, 0))
            {
                ret = max(ret, countZeros(s, i) + n);
                break;
            }               
        }
        
        return ret ;        
    }
    
    int countZeros(string&s, int k)
    {
        int count = 0;
        for (int i=0; i<k; i++)
            count+= s[i]=='0';
        return count;
    }
    
    bool check(string& s, int i, string& t, int j)
    {
        if (j==t.size()) return true;
        if (i==s.size()) return false;
        
        if (t[j]=='1')
        {
            if (s[i]=='1')
                return check(s, i+1, t, j+1);
            else
                return (int)s.size() - i >= (int)t.size() - j;
        }
        else
        {
            while (i<s.size() && s[i]=='1')
                i++;
            if (i==s.size()) return false;
            else return check(s, i+1, t, j+1);
        }
    }    
};
