class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n = s.size();
        vector<int>pre(n);        
        pre[0] = (s[0]=='b');
        for (int i=1; i<n; i++)
            pre[i] = pre[i-1] + (s[i]=='b');
        
        vector<int>suf(n);
        suf[n-1] = (s[n-1]=='a');
        for (int i=n-2; i>=0; i--)
            suf[i] = suf[i+1] + (s[i]=='a');
        
        int ret = INT_MAX;
        for (int i=0; i<n; i++)
        {
            int a = i==0?0:pre[i-1];
            int b = i==n-1?0:suf[i];
            ret = min(ret, a+b);
        }
        return ret;        
    }
};
