class Solution {
public:
    long long maxProduct(string s) 
    {
        // Insert '#'
        string t = "$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        
        // Process t
        vector<int> p(t.size(), 0);
        int mx = 0, id = 0, resLen = 0, resCenter = 0;
        for (int i = 1; i < t.size(); ++i) 
        {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resLen < p[i]) {
                resLen = p[i];
                resCenter = i;
            }
        }
        
        vector<int>len;
        for (int i=2; i<p.size(); i+=2)
        {
            len.push_back(p[i]/2);
        }
                        
        int n = s.size();
        
        vector<int>left(n, 0);        
        left[0] = 1;
        int j = 0;
        for (int i=1; i<n; i++)
        {
            while (j<n && j+len[j]-1 < i)
                j++;
            left[i] = max(left[i-1], (i-j)*2+1);
        }
        
        vector<int>right(n, 0);        
        right[n-1] = 1;
        j = n-1;
        for (int i=n-2; i>=0; i--)
        {
            while (j>=0 && j-len[j]+1 > i)
                j--;            
            right[i] = max(right[i+1], (j-i)*2+1);
        }
            
        long long ret = 0;
        for (int i=0; i<n-1; i++)
            ret = max(ret, (long long)left[i] * (long long)right[i+1]);
            
        return ret;        
    }
};
