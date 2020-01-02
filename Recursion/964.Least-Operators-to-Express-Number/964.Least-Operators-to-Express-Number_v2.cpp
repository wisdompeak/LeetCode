class Solution {    
public:
    int leastOpsExpressTarget(int x, int target) 
    {
        int T = log(target)/log(x)+1;
        vector<int>f(T+1,0);
        vector<int>g(T+1,0);
        vector<int>a(T+1,0);
        
        int i = 0;
        while (target>0)
        {
            a[i] = target%x;
            target /= x;
            i++;
        }
        
        for (int i=T; i>=0; i--)
        {
            if (i==T)
            {
                f[i] = a[i]*i;
                g[i] = (a[i]+1)*i;                
            }
            else
            {
                int s = (i==0)?2:i;
                f[i] = min(f[i+1]+a[i]*s,  g[i+1]+abs(a[i]-x)*s);
                g[i] = min(f[i+1]+(a[i]+1)*s, g[i+1]+abs(a[i]+1-x)*s);
            }
        }
        return f[0]-1;
        
    }
      
};
