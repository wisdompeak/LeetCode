using ll = long long;
class Solution {
public:
    char processStr(string s, long long k) {
        k++;
        int n = s.size();
        s = "#"+s;

        vector<ll>len(n+1);
        for (int i=1; i<=n; i++) {
            char c = s[i];
            if ('a'<=c && c<='z') {
                len[i] = len[i-1]+1;
            } else if (c=='*') {
                len[i] = len[i-1]==0? 0: len[i-1]-1;
            } else if (c=='#') {
                len[i] = len[i-1] * 2;
            } else if (c=='%') {
                len[i] = len[i-1];
            }
        }
        if (k>len[n] || k==0) return '.';

        for (int t=n; t>=1; t--) {
            char c = s[t];
            ll before = len[t-1];
            ll after = len[t];

            if ('a'<=c && c<='z') {
                if (k==after)
                    return c;
            } else if (c=='*') {
                k = k;
            } else if (c=='#') {
                if (k> before)
                    k = k-before;
            } else if (c=='%') {
                k = before+1-k;
            }
        }

        return '.';
    }
};
