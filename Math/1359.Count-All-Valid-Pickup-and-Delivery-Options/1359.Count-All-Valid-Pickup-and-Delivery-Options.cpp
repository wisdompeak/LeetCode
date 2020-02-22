class Solution {
public:
    int countOrders(int n) 
    {
        long ret = 1;
        long M = 1e9+7;
        for (long i=1; i<=n; i++)
            ret = ret*i%M;
        for (long i=2*n-1; i>=1; i-=2)
            ret = ret*i%M;
        return ret;
    }
};
