class Solution {
    vector<int> nxt[1005];
    int matrix[1005][1005];
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            nxt[a].push_back(b);
            nxt[b].push_back(a);
        }
        
        for (int i=0; i<n; i++)
            dfs(i, i, 0);
        
        vector<int>rets;
        for (auto& q: query)
        {
            int start = q[0], end = q[1], node = q[2];               
            int dist = INT_MAX;
            int ret;
            solve(start, end, node, dist, ret);
            rets.push_back(ret);
        }
        return rets;
    }
    
    void dfs(int start, int cur, int dist)
    {        
        for (int j: nxt[cur])
        {
            if (j!=start && matrix[start][j]==0)
            {
                matrix[start][j] = dist+1;
                dfs(start, j, dist+1);
            }                
        }
    }
    
    void solve(int cur, int end, int node, int & dist, int& ret)
    {
        if (matrix[cur][node] < dist)
        {
            dist = matrix[cur][node];
            ret = cur;
        } 
        
        for (int j: nxt[cur])
        {
            if (matrix[cur][end]==matrix[j][end]+1)
            {                               
                solve(j, end, node, dist, ret);
                break;
            }
        }
    }
    
    
};
