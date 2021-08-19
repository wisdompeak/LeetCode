class Solution {
public:
    long long maxProduct(string s) 
    {
        int n = s.size();
        int maxRight = -1;
        int maxCenter = -1;
        vector<int>P(n);
        for (int i=0; i<n; i++)
        {
            int r;
            int j = maxCenter*2-i;
            if (i<=maxRight)
                r = min(P[j], maxRight-i);
            else
                r = 0;
            while (i-r>=0 && i+r<n && s[i-r]==s[i+r])
                r++;
            P[i] = r-1;
            if (i+P[i] > maxRight)
            {
                maxRight = i+P[i];
                maxCenter = i;
            }
        }
                                
        
        vector<int>left(n, 0);        
        left[0] = 1;
        int j = 0;
        for (int i=1; i<n; i++)
        {
            while (j<n && j+P[j] < i)
                j++;
            left[i] = max(left[i-1], (i-j)*2+1);
        }
        
        vector<int>right(n, 0);        
        right[n-1] = 1;
        j = n-1;
        for (int i=n-2; i>=0; i--)
        {
            while (j>=0 && j-P[j] > i)
                j--;            
            right[i] = max(right[i+1], (j-i)*2+1);
        }
            
        long long ret = 0;
        for (int i=0; i<n-1; i++)
            ret = max(ret, (long long)left[i] * (long long)right[i+1]);
            
        return ret;        
    }
};
