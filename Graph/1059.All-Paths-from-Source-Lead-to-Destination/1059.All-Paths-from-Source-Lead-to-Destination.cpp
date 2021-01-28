class Solution {
    int visited[10001];
    vector<vector<int>>nextNodes;
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        nextNodes.resize(n+1);
        for (auto edge: edges)
            nextNodes[edge[0]].push_back(edge[1]);
        
        return dfs(source, destination);        
    }
    
    bool dfs(int cur, int dest)
    {
        visited[cur] = 2;
        if (nextNodes[cur].size() == 0)
        {
            if (cur!=dest)
                return false;
            else
            {
                visited[cur] = 1;
                return true;
            }                
        }
        
        for (auto next: nextNodes[cur])
        {
            if (visited[next]==1) continue;
            if (visited[next]==2) return false;
            if (dfs(next, dest)==false)
                return false;
        }
        visited[cur] = 1;
        return true;
    }
};
