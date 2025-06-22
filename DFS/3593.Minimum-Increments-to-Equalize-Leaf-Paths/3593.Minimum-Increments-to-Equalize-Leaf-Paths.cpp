class Solution {
    vector<int>adj[100005];
public:
    pair<long long, int>dfs(int u, int p, vector<int>&cost) {
        long long maxPath = 0;
        int totalChanged = 0;
        vector<long long>paths;

        for (int v: adj[u]) {
            if (v==p) continue;
            auto [path, changed] = dfs(v, u, cost);            
            maxPath = max(maxPath, path);
            totalChanged += changed;
            paths.push_back(path);            
        }

        int count = 0;
        for (long long p: paths) {
            if (p < maxPath)
                count++;
        }
        
        return {cost[u]+maxPath, totalChanged + count};
    }
    
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto [_, ret ] = dfs(0, -1, cost);

        return ret;
    }
};
