using LL = long long;
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) 
    {
        sort(beans.rbegin(), beans.rend());
        int n = beans.size();
        
        vector<LL>pre(n);
        pre[0] = beans[0];
        for (int i=1; i<n; i++)
            pre[i] = pre[i-1]+(LL)beans[i];        
        
        vector<LL>suf(n);
        suf[n-1] = beans[n-1];
        for (int i=n-2; i>=0; i--)
            suf[i] = suf[i+1]+(LL)beans[i];
                
        LL ret = LLONG_MAX;
        for (int i=0; i<n; i++)
        {
            LL ans = 0;
            ans += pre[i] - (LL)(i+1)*beans[i];
            ans += (i+1==n)?0:suf[i+1];
            ret = min(ret, ans);
        }
        return ret;        
    }
};
