class Solution {
    vector<int>visited;
    vector<vector<int>>graph;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        visited.resize(numCourses, 0);
        graph.resize(numCourses);
        
        for (auto p: prerequisites)        
            graph[p[0]].push_back(p[1]);
        
        
        for (int i=0; i<numCourses; i++)
        {
            if (visited[i]==1) continue;
            if (dfs(i)==false) return false;            
        }
        
        return true;
    }
    
    bool dfs(int cur)
    {
        visited[cur] = 2;
        for (int next: graph[cur])
        {
            if (visited[next]==1) continue;
            if (visited[next]==2) return false;
            if (dfs(next)==false)  return false;
        }
        visited[cur] = 1;
        return true;
    }
};
