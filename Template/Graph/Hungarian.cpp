int num_nodes = 100000;
class Solution {
    vector<int> next[num_nodes];
    int match[num_nodes];
public:
    int minimumOperations(vector<vector<int>>& grid) 
    {
        // construct next[]
        
        for (int i=0; i<num_nodes; i++)
            match[i] = -1;
        
        vector<bool>visited(num_nodes);
        
        int count = 0;
        for (int i=0; i<num_nodes; i++)
        {
            if (match[i]!=-1) continue;
            visited.assign(num_nodes, 0);
            if (dfs(i, visited))
                count++;            
        }
        
        return count;
    }
                                        
    bool dfs(int i, vector<bool>&visited)
    {
        for (int j: next[i])
        {
            if (visited[j]) continue;
            visited[j] = true;
            if (match[j]==-1 || dfs(match[j], visited))
            {
                match[i] = j;
                match[j] = i;
                return true;
            }
        }
        return false;
    }                                        
};
