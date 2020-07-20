class Solution {
    vector<int>visited;
    vector<vector<int>>graph;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        visited.resize(n,0);
        this->graph = graph;
        vector<int>rets;
        for (int i=0; i<n; i++)
            if (DFS(i)) rets.push_back(i);
        return rets;
    }

    bool DFS(int cur)
    {
        if (visited[cur]==1) return true;
        if (visited[cur]==2) return false;
        visited[cur] = 2;
        for (int next: graph[cur])
        {
            if (!DFS(next)) return false;
        }
        visited[cur] = 1;
        return true;
    }
};
