using LL = long long;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) { 
        int n = nums.size(), K = log2(n) + 1;                

        int mn[50005][35];    memset(mn, 0x3f, sizeof(mn));
        int mx[50005][35];    memset(mx, 0xcf, sizeof(mx));
        for (int i = 0; i < n; i++) mn[i][0] = mx[i][0] = nums[i];
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i+(1<<k)-1 < n; i++) {
                mn[i][k] = min(mn[i][k-1], mn[i+(1<<(k-1))][k-1]);
                mx[i][k] = max(mx[i][k-1], mx[i+(1<<(k-1))][k-1]);
            }
        }

        auto GetDiff = [&](int L, int R){
            int k = log2(R-L+1);
            return max(mx[L][k], mx[R-(1<<k)+1][k]) - min(mn[L][k], mn[R-(1<<k)+1][k]);
        };

        auto count_ge = [&](int th) {
            int count = 0;
            int j = 0;
            for (int i=0; i<n; i++) {
                while (j<n && GetDiff(i,j)<th) j++;
                count += n-j;
            }
            return count;
        };

        int lo = 0, hi = 2e9;
        while (lo < hi) {
            int mid = hi-(hi-lo)/2;
            if (count_ge(mid) >= k)
                lo = mid;
            else
                hi = mid-1;
        }
        LL th = lo;

        LL ret_g = 0;
        LL count_g = 0;
        for (int i=0; i<n; i++) {
            int l = i, r = n-1;
            while (l<r) {
                int mid = l+(r-l)/2;
                if (GetDiff(i,mid)>th)
                    r = mid;
                else
                    l = mid+1;
            }
            if (GetDiff(i, r) > th) {
                count_g += n-r;
                for (int j=r; j<n; j++)
                    ret_g += GetDiff(i, j);
            }                            
        }

        LL ret = ret_g + th * (k-count_g);

        return ret;

    }
};
