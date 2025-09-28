using ll = long long;
ll MOD = 1e9+7;

// 矩阵乘法 C = A * B
vector<vector<ll>> matMul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    int m = B[0].size();
    int K = B.size(); // A: n x K, B: K x m
    vector<vector<ll>> C(n, vector<ll>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < K; ++k) {
            ll aik = A[i][k];
            if (aik == 0) continue;
            for (int j = 0; j < m; ++j) {
                C[i][j] += (aik * B[k][j]) % MOD;
                if (C[i][j] >= MOD) C[i][j] -= MOD;
            }
        }
    }
    return C;
}

// 矩阵自乘 (square)
vector<vector<ll>> matMulSquare(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    return matMul(A, B);
}

// 矩阵快速幂 T^e
vector<vector<ll>> matPow(vector<vector<ll>> base, long long e) {
    int K = base.size();
    // initialize res = identity
    vector<vector<ll>> res(K, vector<ll>(K, 0));
    for (int i = 0; i < K; ++i) res[i][i] = 1;
    while (e > 0) {
        if (e & 1) res = matMul(res, base);
        base = matMul(base, base);
        e >>= 1;
    }
    return res;
}

// 矩阵乘向量 v' = M * v
vector<ll> matVecMul(const vector<vector<ll>>& M, const vector<ll>& v) {
    int n = M.size();
    int m = v.size();
    vector<ll> r(n, 0);
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < m; ++j) {
            if (M[i][j] == 0) continue;
            sum += (M[i][j] * v[j]) % MOD;
            if (sum >= MOD) sum -= MOD;
        }
        r[i] = sum % MOD;
    }
    return r;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;

        int K = 2*m;
        vector<vector<ll>>T(K, vector<ll>(K,0));

        for (int i=1; i<m; i++) 
            for (int j=0; j<i; j++)
                T[i][m+j] = 1;      

        for (int i=0; i<m; i++) 
            for (int j=i+1; j<m; j++)
                T[i+m][j] = 1;

        vector<ll>s(K,0);
        for (int i=0; i<2*m; i++)
            s[i] = 1;

        vector<vector<ll>>T_p = matPow(T, n-1);

        vector<ll>sn = matVecMul(T_p, s);

        ll ans = 0;
        for (ll v: sn) {
            ans += v;
            ans%=MOD;
        }
        return ans;
    }
};
