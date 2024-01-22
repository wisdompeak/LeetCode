using LL = long long;
class Solution {
    LL rets[100005];
    int n;
public:
    vector<long long> countOfPairs(int n, int x, int y) 
    {
        if (x>y) return countOfPairs(n,y,x);
        vector<LL>ans;
        this->n = n;
                
        if (x==y || abs(x-y)==1)
        {
            for (int t=1; t<=n; t++)
                ans.push_back((n-t)*2);
            return ans;            
        }
        
        LL ret = 0;
        int d = y-x+1;
        
        helper0(x-1); //AA                
        helper0(n-y); //BB
        
        helper1(x-1, n-y); //AB

        helper2(x-1, (d-1)/2, (d-1)-(d-1)/2);  //AC
        helper2(n-y, (d-1)/2, (d-1)-(d-1)/2);  //BC
        
        for (int t=1; t<=n; t++)
            rets[t] *= 2;
        
        helper3(d); // CC        
        
        for (int t=1; t<=n; t++)
            ans.push_back(rets[t]);
        return ans;
    }
    
    void helper0(LL a)
    {
        for (int t=1; t<=n; t++)
        {
            LL start = 1;
            LL end = a-t;          
            rets[t] += max(0LL, end-start+1);
        }
        
    }
    
    void helper1(LL a, LL b)
    {
        for (int t=1; t<=n; t++)
        {
            LL start = max(a+3-t, 1ll);
            LL end = min(a+2+b-t, a);
            rets[t] += max(0LL, end-start+1);    
        }
    }    

    void helper2(LL a, LL b, LL c)
    {
        for (int t=1; t<=n; t++)
        {
            LL start = max(a+2-t, 1ll);
            LL end = min(a+1+b-t, a);          
            rets[t] += max(0LL, end-start+1);
        }
        
        for (int t=1; t<=n; t++)
        {
            LL start = max(a+2-t, 1ll);
            LL end = min(a+1+c-t, a);          
            rets[t] += max(0LL, end-start+1);
        }
        
        for (int t=1; t<=n; t++)
        {
            if (a>=t)
                rets[t] += 1;            
        }
        
    }
    
    void helper3(LL d)
    {
        for (int t=1; t<=n; t++)
        {
            if (2*t<d)
                rets[t] += d*2;
            else if (2*t==d)
                rets[t] += d;
        }
    }
};
