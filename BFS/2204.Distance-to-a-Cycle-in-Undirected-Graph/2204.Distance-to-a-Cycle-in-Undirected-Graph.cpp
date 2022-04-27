class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) 
    {
        vector<int>degree(n);
        vector<vector<int>>next(n);
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            degree[a]++;
            degree[b]++;
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        vector<int>rets(n);
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (degree[i]==1)
                q.push(i);
        }
                
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                rets[cur] = -1;                
                for (int nxt: next[cur])
                {
                    degree[nxt]--;
                    if (degree[nxt]==1)
                        q.push(nxt);
                }
            }            
        }
        
        while (!q.empty()) q.pop();
        for (int i=0; i<n; i++)
        {
            if (rets[i]==0)
                q.push(i);
        }
                
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int nxt: next[cur])
            {
                if (rets[nxt]!=-1) continue;
                rets[nxt] = rets[cur]+1;
                q.push(nxt);
            }
        }
        return rets;        
    }
};
