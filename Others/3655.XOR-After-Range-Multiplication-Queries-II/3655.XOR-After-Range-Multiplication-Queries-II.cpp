using ll = long long;
ll M = 1e9+7;
ll MOD = 1e9+7;
class Solution {
public:
    long long quickPow(long long x, long long N) 
    {
        if (N <= 0) {
            return 1;
        }
        long long y = quickPow(x, N / 2) % MOD;
        return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
    }

    long long inv(long long x) 
    {
        return quickPow(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<ll>m(n, 1);

        int B = 320;

        vector<vector<int>>small_k_queries[B+1];

        for (auto q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k>B) {
                for (int i=l; i<=r; i+=k) {
                    m[i] = m[i] * v % M;
                }
            } else {
                small_k_queries[k].push_back(q);
            }
        }

        for (int k=1; k<=B; k++) {
            if (small_k_queries[k].empty()) continue;
            vector<ll>diff(n+1, 1);
            for (auto&q: small_k_queries[k]) {
                int l = q[0], r = q[1], k = q[2], v = q[3];
                r = (r-l)/k*k + l;
                diff[l] = diff[l] * v % M;
                if (r+k<=n) diff[r+k] = diff[r+k] * inv(v) % M;
            }

            vector<ll>this_round_m(n+1, 1);
            for (int i=0; i<n; i++) {
                this_round_m[i] = (i>=k?this_round_m[i-k]:1) * diff[i] % M;
            }

            for (int i=0; i<n; i++) {
                m[i] = m[i] * this_round_m[i] % MOD;
            }
                
        }

        int ret = 0;
        for (int i=0; i<n; i++) {
            ll val = (ll)nums[i] * m[i] % M;
            ret ^= (int)val;
        }

        return ret;
    }
};

