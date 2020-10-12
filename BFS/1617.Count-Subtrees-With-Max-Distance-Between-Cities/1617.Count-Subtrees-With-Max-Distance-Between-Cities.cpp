class Solution {
    vector<vector<int>>adj;   
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
    {
        adj.resize(n);
        for (auto edge: edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        vector<int>allow(n);
        vector<int>rets(n,0);
        vector<int>dist(n);
        for (int state=1; state<(1<<n); state++)
        {
            int start;
            int count = 0;
            for (int i=0; i<n; i++)
            {
                if (((state>>i)&1)==1)
                {
                    allow[i]=1;
                    start = i;
                    count++;
                }                    
                else
                    allow[i]=0;
            }
            
            for (int i=0; i<n; i++)
                dist[i] = -1;
            int v1 = bfs(start, dist, allow);

            int countVisited = 0;
            for (int i=0; i<n; i++)
                countVisited += (dist[i]!=-1);
            if (countVisited!=count)
                continue;
            
            for (int i=0; i<n; i++)
                dist[i] = -1;
            int v2 = bfs(v1, dist, allow);
            int maxDist = *max_element(dist.begin(), dist.end());
            
            rets[maxDist]++;
        }
        
        rets.erase(rets.begin());
        return rets;        
    }
    
    int bfs(int start, vector<int>&dis, vector<int>&allow)
    {
        int n = dis.size();
        queue<int> q; 
        q.push(start);       
        dis[start] = 0; 
        int maxDis = 0;
        int maxId = start;
        
        while (!q.empty()) 
        { 
            int cur = q.front();
            q.pop(); 
            
            for (auto next: adj[cur]) 
            {       
                if (allow[next]==0) continue;
                if (dis[next] == -1) 
                { 
                    q.push(next);   
                    dis[next] = dis[cur] + 1; 
                    if (dis[next] > maxDis)
                    {
                        maxDis = dis[next];
                        maxId = next;
                    }
                } 
            } 
        }
        return maxId; 
    }
};
