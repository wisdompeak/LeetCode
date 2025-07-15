using ll = long long;
class Solution {
public:
    char processStr(string s, long long k) {
        k++;
        int n = s.size();
        s = "#"+s;
        vector<ll>len(n+1);
        const ll INF = 1e15+5;

        for (int i=1; i<=n; i++) {
            char c = s[i];
            ll prev = len[i-1];
            ll now = prev;
            if ('a'<=c && c<='z')
                now = prev+1;
            else if (c == '*')
                now = prev>0 ? (prev-1): 0;
            else if (c=='#')
                now = prev*2;
            else if (c=='%')
                now = prev;
            len[i] = min(now, INF);                   
        }
        if (k==0 || k>(ll)len[n]) return '.';

        for (int i=n; i>=1; i--) {
            char c = s[i];
            ll before = len[i-1];
            ll after = len[i];
            if ('a'<=c && c<='z') {
                if (k==after)
                    return c;
            } else if (c=='*') {
                
            } else if (c=='#') {
                if (k>before)
                    k-=before;
            } else if ( c=='%') {
                k = before-k+1;
            }
        }

        return '.';
    }
};
