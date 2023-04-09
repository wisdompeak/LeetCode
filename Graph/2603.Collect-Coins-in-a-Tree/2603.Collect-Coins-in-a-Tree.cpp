class Solution {    
    int ret = 0;
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) 
    {
        int n = coins.size();
        vector<unordered_set<int>>next(n);
        
        vector<int>degree(n);
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].insert(b);
            next[b].insert(a);
            degree[a]++;
            degree[b]++;
        }
        
        vector<int>deleted(n);
        queue<int>q;
        for (int i=0; i<n; i++)
        {            
            if (degree[i]==1 && coins[i]==0)                            
                q.push(i);            
        }
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();                
                q.pop();                                
                deleted[cur] = 1;
                for (int nxt: next[cur])
                {
                    degree[nxt]--;
                    next[nxt].erase(cur);
                    if (degree[nxt]==1 && coins[nxt]==0)                    
                        q.push(nxt);                                            
                }
            }
        }

        vector<int>depth(n, -1);
        for (int i=0; i<n; i++)
        {
            if (degree[i]==1 && deleted[i]==0)
            {
                q.push(i);
                depth[i] = 1;
            }                
        }                
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                int cur = q.front();                
                q.pop();                            
                for (int nxt: next[cur])
                {                    
                    degree[nxt]--;
                    next[nxt].erase(cur);
                    depth[nxt] = max(depth[nxt], depth[cur]+1);
                    if (degree[nxt]==1)
                        q.push(nxt);
                }
            } 
        }                
        
        int ret = 0;
        for (int i=0; i<n; i++)
            ret += (depth[i]>=3);
            
        if (ret >= 1)
            return (ret-1)*2;
        else
            return 0;
    }        
};
