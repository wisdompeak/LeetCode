using LL = long long;
class Solution {
    LL M = 1e9+7;
public:    
    LL quickMul(LL x, LL N) 
    {
        if (N == 0) return 1;
        LL y = quickMul(x, N / 2);
        return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
    }    
    
    int minNonZeroProduct(int p) 
    {
        LL a = (1ll<<(p-1)) - 1;
        LL x = ((1ll<<p)-1) % M;        
        LL ret = quickMul(x-1, a) * x % M;

        return ret;
    }
};
