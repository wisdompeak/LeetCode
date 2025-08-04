using ll = long long;
class Solution {
public:    
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        vector<bool>isStar(n, false);
        ll T = ll(n)*(n+1)/2;
        if (k>T) return -1;

        auto check = [&](int mid) {
            fill(isStar.begin(), isStar.end(), false);
            for (int i=0; i<=mid; i++)
                isStar[order[i]] = true;

            ll sumNon = 0;
            for (int i=0; i<n; ){
                if (isStar[i]) {
                    i++;
                    continue;
                }
                int j = i;
                while (j<n && !isStar[j])
                    j++;
                ll len = j-i;
                sumNon += len*(len+1)/2;
                i = j;
            }            
            return T - sumNon >= k;
        };

        int lo = 0, hi = n-1, ans = -1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if (check(hi)) return hi;
        else return -1;
    }
};
