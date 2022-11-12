class Solution {
public:
    int closestFair(int n) 
    {                
        int count = 0;
        int ret = helper(n, count);
        if (ret!=-1) return ret;            
        
        while (n>=0)
        {
            int ret = helper(n+1, count);
            if (ret!=-1) return ret;
            
            ret = helper(n+2, count);
            if (ret!=-1) return ret;
            
            n = n/10;
            count++;                
        }
        return -1;
    }
    
    int helper(int n, int count)
    {
        int m = n;
        int odd = 0, even = 0;
        while (m>0)
        {
            if (m%2==0)
                even++;
            else
                odd++;  
            m/=10;
        }
        
        int sum = count, diff = odd-even;
        if ((sum + diff) % 2 != 0) return -1;
        int a = (sum + diff) / 2;   // # of 0
        int b = (sum - diff) / 2;   // # of 1           
        if (a<0 || b<0) return -1;
            
        for (int i=0; i<a; i++)
            n = n*10 + 0;
        for (int i=0; i<b; i++)
            n = n*10 + 1;
        return n;
    }
};
