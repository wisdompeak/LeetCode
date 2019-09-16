class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>visited(n,-1);
        
        for (int i=0; i<n; i++)
        {
            if (visited[i]!=-1)
                continue;
            
            queue<pair<int,int>>q;
            q.push({i,0}); // {node, group}
            visited[i] = 0;
        
            while (!q.empty())
            {
                int node = q.front().first;
                int group = q.front().second;
                q.pop();
                        
                for (auto next: graph[node])
                {                   
                
                    if (visited[next]!=-1)
                    {
                        if (visited[next]!=1-group)
                            return false;
                    }
                    else
                    {
                        visited[next] = 1-group;                
                        q.push({next, 1-group});
                    }
                }
            }        
        }
                
        return true;        
    }
};
