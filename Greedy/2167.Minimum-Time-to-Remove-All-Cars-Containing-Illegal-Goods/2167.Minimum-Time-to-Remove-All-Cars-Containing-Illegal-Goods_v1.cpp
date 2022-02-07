class Solution {
public:
    int minimumTime(string s) 
    {
        int n = s.size();
        vector<int>pre(n);
                
        vector<int>left(n);
        left[0] = s[0]=='0'?0:1;
        for (int i=1; i<n; i++)
        {
            if (s[i]=='0')
                left[i] = left[i-1];
            else
                left[i] = min(2+left[i-1], i+1);
        }
                
        vector<int>right(n);
        right[n-1] = s[n-1]=='0'?0:1;
        for (int i=n-2; i>=0; i--)
        {
            if (s[i]=='0')
                right[i] = right[i+1];
            else
                right[i] = min(2+right[i+1], n-i);
        }
        
        int ret = min(left[n-1], right[0]);
        for (int i=1; i<n-1; i++)
            ret = min(ret, left[i]+right[i+1]);
                        
        return ret;
    }
};
