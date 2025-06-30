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

int main {
  DSU dsu(n);
  dsu.unite(u,v);
  if (dsu.find(u)==dsu.find(v) {}
}
