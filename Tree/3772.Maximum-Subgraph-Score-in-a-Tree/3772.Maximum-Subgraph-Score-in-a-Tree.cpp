class Solution {
    vector<int>next[100005];
    int w[100005];
    int dp1[100005];
    int dp2[100005];

public:
    void dfs1(int cur, int parent) {
        dp1[cur] = w[cur];
        for (int nxt: next[cur]) {
            if (nxt==parent) continue;
            dfs1(nxt, cur);
            dp1[cur] += max(0, dp1[nxt]);
        }
    }

    void dfs2(int cur, int parent) {
        for (int nxt: next[cur]) {
            if (nxt==parent) continue;
            dp2[nxt] = max(0, dp1[cur]-max(0, dp1[nxt]) + dp2[cur]);
            dfs2(nxt, cur);
        }
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        for (int i=0; i<n; i++)
            w[i] = (good[i]==1?1:-1);
        for (auto edge: edges) {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        dfs1(0, -1);

        dp2[0] = 0;
        dfs2(0, -1);

        vector<int>rets(n);
        for (int i=0; i<n; i++) {
            rets[i] = dp1[i]+dp2[i];
        }
        return rets;

    }
};
