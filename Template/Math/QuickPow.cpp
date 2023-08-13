class Solution {
long long M = 1e9+7;
public:
    long long quickMul(long long x, long long N) {
        if (N == 0) {
            return 1;
        }
        LL y = quickMul(x, N / 2) % M;
        return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
    }

    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
