class Solution {
    int connect[401][401];
    int degree[401];
    vector<int> next[401];
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        for (auto e:edges)
        {
            connect[e[0]][e[1]] = 1;
            connect[e[1]][e[0]] = 1;
            degree[e[0]] += 1;
            degree[e[1]] += 1;
            
            int x = min(e[0],e[1]), y = max(e[0],e[1]);            
            next[x].push_back(y);            
        }
        
        int ret = INT_MAX;
        for (int a = 1; a <=n; a++)
        {
            for (int i=0; i<next[a].size(); i++)
                for (int j=i+1; j<next[a].size(); j++)
                {
                    int b = next[a][i], c = next[a][j];
                    if (connect[b][c]==1)
                        ret  = min(ret, degree[a]+degree[b]+degree[c]-6);
                }
        }
        
        return ret==INT_MAX? -1:ret;
    }
};
