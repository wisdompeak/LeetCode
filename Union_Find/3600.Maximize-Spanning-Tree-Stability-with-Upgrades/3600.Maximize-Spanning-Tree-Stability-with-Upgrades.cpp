class Solution {
public:
    struct DSU {
        vector<int> p, r;
        DSU(int n): p(n,-1), r(n,0) {
            iota(p.begin(), p.end(), 0);
        }
        int find(int x) {
            return p[x]==x ? x : p[x]=find(p[x]);
        }
        bool unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a,b);
            p[b] = a;
            if (r[a]==r[b]) ++r[a];
            return true;
        }
    };

    bool isOK(int T, int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int count = 0;
        int upgrade = 0;
        
        vector<vector<int>>candidates; // upgrade, u,v
        for (auto& e: edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) {
                if (s<T) return false;
                dsu.unite(u,v);
                count++;
            } else {
                if (s>=T)
                    candidates.push_back({0, u, v});
                else if (2*s>=T)
                    candidates.push_back({1, u, v});
            }
        }

        sort(candidates.begin(), candidates.end());

        for (auto& cand: candidates) {
            int u = cand[1], v = cand[2];
            if (count==n-1) break;
            if (dsu.find(u)!=dsu.find(v)) {
                dsu.unite(u,v);
                count++;
                upgrade += cand[0];
                if (upgrade > k) return false;
            }
        }

        for (int i=0; i<n; i++)
            if (dsu.find(i)!=dsu.find(0))
                return false;

        return count==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 1, hi = 1e5*2;
        while (lo < hi) {
            int mid = hi-(hi-lo)/2;
            if (isOK(mid, n, edges, k))
                lo = mid;
            else
                hi = mid-1;
        }
        if (isOK(lo, n, edges, k))
            return lo;
        else
            return -1;        
    }
};
