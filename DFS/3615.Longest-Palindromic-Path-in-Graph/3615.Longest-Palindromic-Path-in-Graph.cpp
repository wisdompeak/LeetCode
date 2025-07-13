class Solution {
    vector<int>adj[14];
    int memo[14][14][1<<14];
    string label;
public:
    int dfs(int u, int v, int mask) {        
        if (memo[u][v][mask]!=-1) return memo[u][v][mask];
        int ret = 0;
        for (int u2: adj[u]) {
            if (mask&(1<<u2)) continue;
            for (int v2: adj[v]) {
                if (u2==v2) continue;
                if (mask&(1<<v2)) continue;
                if (label[u2]!=label[v2]) continue;
                int newMask = mask | (1<<u2) | (1<<v2);
                ret = max(ret, 1+dfs(u2,v2, newMask));
            }            
        }
        memo[u][v][mask] = ret;
        return ret;        
    }
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        this->label = label;
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        memset(memo, -1, sizeof(memo));

        int ret = 1;
        for (int u=0; u<n; u++) {
            int mask = 1<<u;
            int pairs = dfs(u, u, mask);
            ret = max(ret, 1+2*pairs);
        }

        for (int u=0; u<n; u++) 
            for (int v: adj[u]) {
                if (u<v && label[u]==label[v]) {
                    int mask = (1<<u) | (1<<v);
                    int pairs = dfs(u,v, mask);
                    ret = max(ret, 2+2*pairs);
                }
            }

        return ret;
    }
};
