using ll = long long;
const int MAXN = 100000;
const int LOGN = 17;
class Solution {
public:    
    vector<pair<int,int>> adj[MAXN];
    int up[MAXN][LOGN+1];
    int depth[MAXN];
    ll distRoot[MAXN];

    void dfs(int cur, int parent)
    {
        up[cur][0] = parent;
        for(auto &[v,w]: adj[cur])
        {
            if(v == parent) continue;
            depth[v] = depth[cur] + 1;
            distRoot[v] = distRoot[cur] + w;
            dfs(v, cur);
        }
    }

    int lca(int a, int b)
    {
        if(depth[a] < depth[b]) swap(a,b);
        int diff = depth[a] - depth[b];
        for(int k = 0; k <= LOGN; k++){
            if(diff & (1<<k)) a = up[a][k];
        }
        if(a == b) return a;
        for(int k = LOGN; k >= 0; k--){
            if(up[a][k] != up[b][k]){
                a = up[a][k];
                b = up[b][k];
            }
        }
        return up[a][0];
    }

    ll dist(int a, int b)
    {
        int c = lca(a,b);
        return distRoot[a] + distRoot[b] - 2*distRoot[c];
    }

    ll stepUp(int u, int k) {        
        for (int i=LOGN; i>=0; i--) {
            if ((k>>i)&1) {
                u = up[u][i];
            }
        }
        return u;
    }

    void solve(vector<vector<int>>& edges) {
        for (auto& edge: edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        depth[0] = 0;
        distRoot[0] = 0;
        dfs(0, 0);

        for(int k = 1; k <= LOGN; k++) {
            for(int v = 0; v < n; v++) {
                up[v][k] = up[up[v][k-1]][k-1];
            }
        }

        // Solve your problem.
    }
