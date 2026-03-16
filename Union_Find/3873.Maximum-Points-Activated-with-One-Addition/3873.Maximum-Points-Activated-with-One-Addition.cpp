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

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        unordered_map<int,vector<int>>MapX;
        unordered_map<int,vector<int>>MapY;
        for (int i=0; i<n; i++) {
            MapX[points[i][0]].push_back(i);
            MapY[points[i][1]].push_back(i);
        }

        for (auto [k,v]: MapX) {
            int j = v[0];
            for (int i=1; i<v.size(); i++)
                dsu.unite(j, v[i]);
        }

        for (auto [k,v]: MapY) {
            int j = v[0];
            for (int i=1; i<v.size(); i++)
                dsu.unite(j, v[i]);
        }

        unordered_map<int, int>leaders;
        for (int i=0; i<n; i++)
            leaders[dsu.find(i)]++;

        vector<int>temp;
        for (auto [k,v]: leaders)
            temp.push_back(v);

        sort(temp.rbegin(),temp.rend());
        if (temp.size()==1) return temp[0]+1;
        else return temp[0]+temp[1]+1;
    }
};
