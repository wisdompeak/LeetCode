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

    int stepUp(int u, int k) {        
        for (int i=16; i>=0; i--) {
            if ((k>>i)&1) {
                u = up[u][i];
            }
        }
        return u;
    }

    ll dist(int a, int b)
    {
        int c = lca(a,b);
        return distRoot[a] + distRoot[b] - 2*distRoot[c];
    }
    
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for (int i = 0; i < n-1; i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
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
        
        vector<int>rets;
        for (auto& q: queries)
        {                    
            int u = q[0], v = q[1];
            int c = lca(u,v);
            ll total = dist(u,c)+dist(c,v);

            int step1 = depth[u]-depth[c];
            int step2 = depth[v]-depth[c];
            
            int low = 0, high = step1+step2;
            int k;
            while (low < high) {
                int mid = low + (high-low)/2;
                ll d;
                if (mid <= step1) {
                    k = stepUp(u, mid);
                    d = distRoot[u] - distRoot[k];
                } else {
                    k = stepUp(v, step2 - (mid-step1));
                    d = total - (distRoot[v] - distRoot[k]);
                }
                if (d >= total*0.5) 
                    high = mid;
                else
                    low = mid+1;
            }
            int step = low;
            if (step<=step1)
                rets.push_back(stepUp(u, step));
            else
                rets.push_back(stepUp(v, step2-(step-step1)));
        }

        return rets;
    }
};
