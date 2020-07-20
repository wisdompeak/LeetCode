class Solution {
    vector<int>visited;
    vector<vector<int>>next;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        visited.resize(numCourses, 0);
        next.resize(numCourses);        
        for (auto p: prerequisites)        
            next[p[0]].push_back(p[1]);
        
        for (int i=0; i<numCourses; i++)
        {            
            if (dfs(i)==false) return false;            
        }
        
        return true;
    }
    
    bool dfs(int cur)
    {
        if (visited[cur]==1) return true;

        visited[cur] = 2;
        for (int next: next[cur])
        {
            if (visited[next]==1) continue;
            if (visited[next]==2) return false;
            if (dfs(next)==false)  return false;
        }
        visited[cur] = 1;
        return true;
    }
};
