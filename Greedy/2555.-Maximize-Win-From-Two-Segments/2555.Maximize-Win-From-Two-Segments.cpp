class Solution {
public:
    int maximizeWin(vector<int>& p, int k) 
    {
        int n = p.size();
        if (p[n-1]-p[0] <= 2*k) return p.size();
        
        vector<int>pre(n);
        vector<int>post(n);

        int i = 0;
        int mx = 0;
        for (int j=0; j<n; j++)
        {
            while (p[j]-p[i]>k)
                i++;
            mx = max(mx, j-i+1);
            pre[j] = mx;
        }
        
        int j = n-1;
        mx = 0;
        for (int i=n-1; i>=0; i--)
        {
            while (p[j]-p[i]>k)
                j--;
            mx = max(mx, j-i+1);
            post[i] = mx;
        }
        
        int ret = 0;        
        for (int i=0; i+1<n; i++)
            ret = max(ret, pre[i] + post[i+1]);
        
        return ret;
    }
};
