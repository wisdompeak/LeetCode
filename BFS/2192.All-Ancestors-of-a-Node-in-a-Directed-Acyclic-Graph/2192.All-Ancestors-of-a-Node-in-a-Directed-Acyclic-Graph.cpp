class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>next(n);
        vector<int>indegree(n);
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            indegree[b]++;
        }
        
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
                q.push(i);                
        }
        
        vector<unordered_set<int>>rets(n);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto x: next[cur])
            {                
                for (auto y: rets[cur])
                    rets[x].insert(y);
                rets[x].insert(cur);
                indegree[x]--;
                if (indegree[x]==0)
                    q.push(x);
            }
        }
        
        vector<vector<int>>ans(n);
        for (int i=0; i<n; i++)
            for (auto x: rets[i])
                ans[i].push_back(x);
        
        
        for (int i=0; i<n; i++)
            sort(ans[i].begin(), ans[i].end());
        
        return ans;
    }
};
