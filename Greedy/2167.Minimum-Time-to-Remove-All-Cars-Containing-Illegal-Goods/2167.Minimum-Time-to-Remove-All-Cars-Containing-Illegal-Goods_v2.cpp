class Solution {
public:
    int minimumTime(string s) 
    {
        int n = s.size();
        
        vector<int>pre(n);        
        pre[0] = (s[0]=='1');
        for (int i=1; i<n; i++)
            pre[i] = pre[i-1]+(s[i]=='1');
        
        vector<int>arr(n);
        for (int i=0; i<n; i++)
            arr[i] = 2*pre[i] - i;
        
        int ret = n;        
        int preMax = 1;
        for (int i=0; i<n; i++)
        {
            ret = min(ret, arr[i]-preMax+n);
            preMax = max(preMax, arr[i]);
        }            
        
        return ret;
    }
};
