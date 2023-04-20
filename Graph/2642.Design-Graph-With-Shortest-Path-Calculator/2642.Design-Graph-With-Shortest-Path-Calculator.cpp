class Graph {
    int n;
    int dp[100][100];
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)            
                dp[i][j] = INT_MAX/3;                            
            dp[i][i] = 0;
        }            
                
        for (auto& edge: edges)        
            dp[edge[0]][edge[1]] = edge[2];
        
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)            
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);                
    }
    
    void addEdge(vector<int> edge) 
    {
        int a = edge[0], b = edge[1];
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                dp[i][j] = min(dp[i][j], dp[i][a]+edge[2]+dp[b][j]);                            
    }
    
    int shortestPath(int node1, int node2) 
    {
        int ret = dp[node1][node2];
        if (ret==INT_MAX/3) return -1;
        else return ret;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
