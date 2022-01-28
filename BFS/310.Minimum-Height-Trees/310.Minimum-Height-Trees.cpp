class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (n==1) return {0};
        if (n==2) return {0,1};
        
        vector<vector<int>>next(n);
        vector<int>degree(n);
        
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            degree[a]++;
            degree[b]++;
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        queue<int>q;
        vector<int>visited(n);
        for (int i=0; i<n; i++)
        {
            if (degree[i]==1)
                q.push(i);
        }
        
        int count = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                count++;
                visited[cur] = 1;
                for (int nxt: next[cur])
                {
                    degree[nxt]--;
                    if (degree[nxt]==1)
                        q.push(nxt);
                }                
            }
            if (count==n-1 || count==n-2)
                break;
        }
        
        vector<int>rets;
        while (!q.empty())
        {
            rets.push_back(q.front());
            q.pop();                
        }
            
        return rets;
        
    }
};
