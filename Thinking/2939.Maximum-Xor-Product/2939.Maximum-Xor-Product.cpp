using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) 
    {
        LL A = ((a>>n)<<n);
        LL B = ((b>>n)<<n);
        
        if (A<B) return maximumXorProduct(b,a,n);
        
        if (A==B)
        {
            int flag = 0;
            for (int k=n-1; k>=0; k--)
            {
                LL bit1 = ((a>>k)&1LL);
                LL bit2 = ((b>>k)&1LL);
                if (bit1==bit2)
                {
                    a = a - (bit1<<k) + (1LL<<k);
                    b = b - (bit2<<k) + (1LL<<k);
                }
                else
                {
                    if (flag==0)
                    {
                        a = a - (bit1<<k) + (1LL<<k);
                        b = b - (bit2<<k);
                        flag = 1;
                    }
                    else
                    {
                        a = a - (bit1<<k);
                        b = b - (bit2<<k) + (1LL<<k);
                    }
                }
            }            
        }
        
        if (A>B)
        {
            for (int k=n-1; k>=0; k--)
            {
                LL bit1 = ((a>>k)&1LL);
                LL bit2 = ((b>>k)&1LL);
                if (bit1==bit2)
                {
                    a = a - (bit1<<k) + (1LL<<k);
                    b = b - (bit2<<k) + (1LL<<k);
                }
                else
                {
                    a = a - (bit1<<k);
                    b = b - (bit2<<k) + (1LL<<k);
                }
            }            
        }
    
        return a%M*(b%M)%M;
        
    }
};
