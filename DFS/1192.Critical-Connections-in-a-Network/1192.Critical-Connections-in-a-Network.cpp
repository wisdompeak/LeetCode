class Solution {
    vector<vector<int>>rets;
    vector<vector<int>>next;
    int time = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        next.resize(n);
        for (auto x:connections)
        {
            next[x[0]].push_back(x[1]);
            next[x[1]].push_back(x[0]);
        }
            
        vector<bool>visited(n);
        vector<int>dfn(n,0);
        vector<int>low(n,0);
        vector<int>parent(n,-1);
        
        for (int i = 0; i < n; i++) 
        {            
            if (visited[i] == false) 
                DFS(i, visited, dfn, low, parent); 
        }
        
        return rets;
    }
    
    
    void DFS(int u, vector<bool>&visited, vector<int>&dfn, vector<int>&low, vector<int>&parent) 
    {  
        visited[u] = true; 
    
        dfn[u] = low[u] = ++time; 
              
        for (int v : next[u]) 
        { 
            if (v == parent[u])
                continue;
            
            if (!visited[v])
            { 
                parent[v] = u; 
                DFS(v, visited, dfn, low, parent); 
  
                if (low[v] > dfn[u]) rets.push_back({v,u}); // critical edge
                
                // if(low[v] >= dfn[u]), then u is a critical vertex
                
                low[u]  = min(low[u], low[v]); 
            }   
            else
            {                
                low[u]  = min(low[u], dfn[v]); 
            }
        } 
    } 
    
};
