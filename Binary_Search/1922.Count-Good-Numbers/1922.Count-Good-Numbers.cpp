class Solution {
    long long M = 1e9+7;
public:
    int countGoodNumbers(long long n) 
    {
        long long a = n/2;
        long long b = n-a;

        return mypow(5,b)*mypow(4,a)%M;
    }

    long long mypow(long long x, long long k)
    {
        if (k==0) return 1;
        long long y = mypow(x, k/2);

        if (k%2==0)        
            return y*y%M;
        else
            return y*y%M*x%M;        
    }
};
