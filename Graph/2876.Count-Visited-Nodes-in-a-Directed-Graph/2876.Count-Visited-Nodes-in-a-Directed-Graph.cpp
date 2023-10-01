class Solution {
    int next[100005];
    int indegree[100005];    
public:
    vector<int> countVisitedNodes(vector<int>& edges) 
    {
        int n = edges.size();
        vector<int>rets(n);
                
        for (int i=0; i<n; i++)
        {            
            next[i] = edges[i];
            indegree[edges[i]] += 1;
        }
        
        queue<int>q;
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
                q.push(i);
        }
        
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();
                q.pop();
                int nxt = next[cur];
                indegree[nxt]--;
                if (indegree[nxt]==0)
                    q.push(nxt);
            }
        }
        
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0) continue;
            if (rets[i]!=0) continue;
                        
            int j = i;
            int len = 1;
            while (next[j]!=i)
            {
                len++;
                j = next[j];                
            }
            
            j = i;
            while (next[j]!=i)
            {
                rets[j] = len;
                j = next[j];
            }                
        }
                
        for (int i=0; i<n; i++)
        {
            if (indegree[i]!=0) continue;
            dfs(i, rets);
        }
        
        return rets;
    }
    
    int dfs(int cur, vector<int>&rets)
    {
        if (rets[cur]!=0)
            return rets[cur];
        
        rets[cur] = dfs(next[cur], rets) + 1;
        return rets[cur];
    }
};
