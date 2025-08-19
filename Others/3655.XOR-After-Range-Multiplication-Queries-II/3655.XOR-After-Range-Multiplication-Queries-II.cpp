using ll = long long;
class Solution {
    int MOD = 1e9+7;
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        const int MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    long long modInverse(long long n) {
        const int MOD = 1e9 + 7;
        return power(n, MOD - 2);
    }
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int B = 400;

        vector<ll>multipliers(n,1);

        vector<vector<int>>small_k_queries[B+1];

        for (auto q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k>B) {
                for (int i=l; i<=r; i+=k)
                    multipliers[i] = (multipliers[i]*v) % MOD;
            } else {
                small_k_queries[k].push_back(q);
            }
        }

        for (int k=1; k<=B; k++) {
            if (small_k_queries[k].empty())
                continue;
            vector<ll>diff(n+1,1);
            for (auto& q: small_k_queries[k]) {
                int l = q[0], r = q[1], v = q[3];
                r = (r-l)/k*k+l;
                diff[l] = (diff[l]*v)%MOD;
                if (r+k<n+1) diff[r+k] = diff[r+k] * modInverse(v) % MOD;                
            }

            for (int i=k; i<n; i++) 
                diff[i] = diff[i]*diff[i-k] % MOD;

            for (int i=0; i<n; i++)
                multipliers[i] = multipliers[i] * diff[i] % MOD;
        }

        int ret = 0;
        for(int i=0; i<n; i++) {
            ll val = (ll)nums[i]*multipliers[i]%MOD;
            ret ^= (int)val;
        }
        return ret;
    }
};
