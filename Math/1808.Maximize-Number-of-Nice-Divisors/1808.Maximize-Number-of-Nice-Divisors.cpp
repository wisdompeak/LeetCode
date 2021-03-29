class Solution {
public:
    int maxNiceDivisors(int primeFactors) 
    {
        if (primeFactors==1) return 1;
        if (primeFactors==2) return 2;
        if (primeFactors==3) return 3;
        if (primeFactors==4) return 4;
        int a,b;
        if (primeFactors%3==0)
        {
            a = primeFactors/3;
            b = 0;
        }
        else if (primeFactors%3==2)
        {
            a = (primeFactors-2)/3;
            b = 1;
        }
        else
        {
            a = (primeFactors-4)/3;
            b = 2;
        }
        long long ret = 1;
        ret = ret * quickMul(3, a) % M;
        ret = ret * quickMul(2, b) % M;
        return ret;

    }

    long long M = 1e9+7;

    long long quickMul(long long x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        long long y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y % M: y * y * x % M;
    }
};
