using ll = long long;
class Solution {
public:
    int countLessOrEqual(vector<vector<int>>& lists, int mask, int val) {
        int n = lists.size();
        int count = 0;
        for (int i=0; i<n; i++) {
            if (((mask>>i)&1)==0) continue;
            auto iter = upper_bound(lists[i].begin(), lists[i].end(), val);
            count += iter - lists[i].begin();
        }
        return count;
    }

    int find_median(vector<vector<int>>& lists, int mask, int c) {        
        int low = -INT_MAX/2, high = INT_MAX/2;
        while (low < high) {
            int mid = low+(high-low)/2;
            if (countLessOrEqual(lists, mask, mid)<c) 
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }

    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        vector<int>len(1<<n);
        vector<int>med(1<<n);
        
        for (int mask = 1; mask < (1<<n); mask++) {    
            int m = 0;
            for (int i=0; i<n; i++) {
                if (((mask>>i)&1)==0) continue;
                m += lists[i].size();
            }        
            med[mask] = find_median(lists, mask, (m+1)/2);
            len[mask] = m;
        }
        

        vector<ll>dp(1<<n, LLONG_MAX/2);
        for (int i=0; i<n; i++) dp[1<<i] = 0;

        for (int mask=1; mask<(1<<n); mask++) {
            if (__builtin_popcount(mask)==1) continue;

            for (int subset=mask; subset>0; subset=(subset-1)&mask)
            {
                int other = mask^subset;
                if (other==0) continue;
                if (subset > other) continue;
                ll cost = dp[subset] + dp[other] + len[subset] + len[other] + llabs(med[subset]-med[other]);
                dp[mask] = min(dp[mask], cost);
            }

        }

        return dp[(1<<n)-1];
    }
};
