class Solution {
    vector<pair<int,int>> next[100005];
    vector<int>rets;
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back({b, 1});
            next[b].push_back({a, -1});
        }
        
        int count = dfs1(0, -1);
                
        rets.resize(n);
        
        dfs2(0, -1, count);
        
        return rets;
    }

    int dfs1(int cur, int parent)
    {
        int ret = 0;
        for (auto& [nxt, dir]: next[cur])
        {
            if (nxt==parent) continue;
            if (dir==1)
                ret += dfs1(nxt, cur);
            else
            {                
                ret += dfs1(nxt, cur) + 1;
            }
        }
        return ret;
    }
    
    void dfs2(int cur, int parent, int count)
    {
        rets[cur] = count;
        for (auto& [nxt, dir]: next[cur])
        {
            if (nxt==parent) continue;
            if (dir == 1)
                dfs2(nxt, cur, count+1);
            else
                dfs2(nxt, cur, count-1);            
        }
    }
    
    
};
