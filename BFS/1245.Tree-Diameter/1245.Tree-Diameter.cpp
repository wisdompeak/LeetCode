class Solution {
    vector<vector<int>>adj;
    int V;
public:
    int treeDiameter(vector<vector<int>>& edges) 
    {
        V = edges.size()+1;
        adj.resize(V);
        for (auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        auto t1 = bfs(0); 
        auto t2 = bfs(t1.first); 
        return t2.second;        
    }
        
    pair<int, int> bfs(int u) 
    { 
        vector<int>dis(V, -1);
        queue<int> q; 
        q.push(u); 
      
        dis[u] = 0; 
        
        while (!q.empty()) 
        { 
            int t = q.front();       
            q.pop(); 
            
            for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
            { 
                int v = *it; 
                if (dis[v] == -1) 
                { 
                    q.push(v);   
                    dis[v] = dis[t] + 1; 
                } 
            } 
        } 
  
        int maxDis = 0; 
        int nodeIdx; 
          
        for (int i = 0; i < V; i++) 
        { 
            if (dis[i] > maxDis) 
            { 
                maxDis = dis[i]; 
                nodeIdx = i; 
            } 
        } 
        return make_pair(nodeIdx, maxDis); 
    }     
};
