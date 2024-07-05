class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {              
        int a = treeDiameter(edges1);
        int b = treeDiameter(edges2);
        return max({(a+1)/2+(b+1)/2+1, a, b});        
    }
    
    int treeDiameter(vector<vector<int>>& edges) 
    {
        int n = edges.size()+1;
        vector<vector<int>>next(n);
        for (auto edge: edges)
        {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }
        auto t1 = bfs(next, 0);
        auto t2 = bfs(next, t1.first);
        return t2.second;        
    }

    pair<int, int> bfs(vector<vector<int>>&next, int u) 
    { 
        int n = next.size();
        vector<int>dis(n, -1);
        queue<int> q; 
        q.push(u); 
      
        dis[u] = 0; 
        
        while (!q.empty()) 
        { 
            int t = q.front();       
            q.pop(); 
            
            for (auto it = next[t].begin(); it != next[t].end(); it++) 
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
        int nodeIdx = 0; 
          
        for (int i = 0; i < n; i++) 
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
