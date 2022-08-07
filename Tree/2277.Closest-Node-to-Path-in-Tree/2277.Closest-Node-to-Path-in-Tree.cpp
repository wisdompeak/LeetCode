class Solution {
    vector<int>next[1005];
    int matrix[1005][1005];
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        for (int i=0; i<n; i++)
            dfs(i,i,0);
                
        vector<int>rets;
        for (auto& q: query)
        {
            int start = q[0], end = q[1], node = q[2];
            int dist = INT_MAX;
            int ret;
            
            int cur = start;
            while (1)
            {
                if (matrix[cur][node] < dist)
                {
                    dist = matrix[cur][node];
                    ret = cur;
                }
                if (cur==end) break;
                
                for (int j: next[cur])
                {
                    if (matrix[cur][end]==matrix[j][end]+1)
                    {
                        cur = j;
                        break;
                    }
                }                
            }
            rets.push_back(ret);                        
        }
        
        return rets;
             
    }
    
    void dfs(int root, int cur, int dist)
    {
        for (int j: next[cur])
        {
            if (j!=root && matrix[root][j]==0)
            {
                matrix[root][j] = dist+1;
                dfs(root, j, dist+1);                
            }            
        }
    }
};
