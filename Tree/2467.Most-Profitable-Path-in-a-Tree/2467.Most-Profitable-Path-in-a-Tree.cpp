class Solution {
    vector<int> next[100005];
    int b[100005];
    int bob;
    int n;
    int ret = INT_MIN;
    vector<int>amount;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        this->n = amount.size();
        this->bob = bob;
        this->amount = amount;
        
        for (int i=0; i<n; i++) b[i] = INT_MAX/2;
        
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        dfs(0, -1, 0);
        
        dfs2(0, -1, 0, 0);
        
        return ret;
    }
    
    void dfs(int cur, int parent, int step)
    {        
        if (cur==bob)
        {
            b[cur] = 0;
            return;            
        }
        
        int near = INT_MAX/2;
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            dfs(nxt, cur, step+1);
            near = min(near, b[nxt]);
        }
        
        b[cur] = min(near+1, INT_MAX/2);
        
        return;
    }
    
    void dfs2(int cur, int parent, int step, int score)
    {                
        if (step == b[cur])
            score += amount[cur]/2;
        else if (step < b[cur])
            score += amount[cur];        
        
        if (next[cur].size()==1 && next[cur][0]==parent)
            ret = max(ret, score);
        
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            dfs2(nxt, cur, step+1, score);
        }
    }
};
