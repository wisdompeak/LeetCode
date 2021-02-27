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
        
        int ret = min(pre[n-1], suf[0]);
        for (int i=0; i<n-1; i++)
            ret = min(ret, pre[i] + suf[i+1]);
        
        return ret;
    }
};
