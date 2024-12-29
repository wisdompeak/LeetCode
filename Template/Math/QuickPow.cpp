class Solution {
long long MOD = 1e9+7;
public:
    long long quickMul(long long x, long long N) {
        if (N == 0) {
            return 1;
        }
        LL y = quickMul(x, N / 2) % MOD;
        return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
    }

    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    // n can be negative.
    double myPow(double x, int n) {        
        return n >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -n);
    }
};
