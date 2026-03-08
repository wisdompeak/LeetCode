using ll = long long;
class Solution {
public:    
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<ll>pref(n+1,0);
        for (int i=0; i<n; i++)
            pref[i+1] = pref[i]+(s[i]=='1');

        auto cost=[&](int l, int r) -> ll {
            int L = r-l+1;
            int X=pref[r+1]-pref[l];
            if (X==0) return (long long)flatCost;
            else return 1LL*L*X*encCost;
        };
        
        std::function<ll(int,int)> dfs = [&](int l, int r) -> ll {
            int len = r-l+1;
            if (len<=0) return 0;
            if (len%2==1) return cost(l,r);

            return min(cost(l,r), dfs(l, l+len/2-1) + dfs(l+len/2, r));
        };
                
        return dfs(0, n-1);
    }    
};
