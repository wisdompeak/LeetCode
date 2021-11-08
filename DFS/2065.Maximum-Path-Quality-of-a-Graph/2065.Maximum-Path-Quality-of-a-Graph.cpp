class Solution {
    int ret = 0;
    int maxTime;
    vector<pair<int,int>>next[1000];
    int visited[1000];
    vector<int>values;
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) 
    {
        this->maxTime = maxTime;
        this->values = values;

        int n = values.size();        
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1], t = edge[2];
            next[a].push_back({b,t});
            next[b].push_back({a,t});
        }
        
        visited[0] = 1;        
        dfs(0, values[0], 0);
        return ret;        
    }

    void dfs(int cur, int totalVal, int totalTime)
    {
        if (totalTime > maxTime) return;
        if (cur==0) ret = max(ret, totalVal);

        for (auto x: next[cur])
        {
            int nxt = x.first, t = x.second;
            visited[nxt]++;
            dfs(nxt, totalVal + (visited[nxt]==1?values[nxt]:0), totalTime+t);
            visited[nxt]--;
        }
    }
};
