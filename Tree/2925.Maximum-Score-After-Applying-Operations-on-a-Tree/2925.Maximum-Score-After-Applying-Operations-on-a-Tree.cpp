using LL = long long;
class Solution {
    vector<int>next[20005];
    LL subtree[20005];
    vector<int>values;
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        this->values = values;
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        dfs0(0, -1);
        return dfs(0, -1);
        
    }
    
    LL dfs0(int cur, int parent)
    {
        LL sum = values[cur];
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            sum += dfs0(nxt, cur);
        }
        subtree[cur] = sum;
        return sum;
    }
    
    
    LL dfs(int cur, int parent)
    {
        if (next[cur].size()==1 && cur!=0)
        {
            return 0;
        }
        
        LL sum = values[cur];
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            sum += dfs(nxt, cur);
        }
        
        return max(sum, subtree[cur]-values[cur]);
    }
};
