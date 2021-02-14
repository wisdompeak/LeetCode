class Solution {
    int c[401][401];    
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        for (auto e:edges)
        {
            c[e[0]][e[1]] = 1;
            c[e[1]][e[0]] = 1;
        }
        
        vector<int> next[401];
        vector<int> next2[401];

        for (auto e:edges)
        {
            int a = min(e[0], e[1]);
            int b = max(e[0], e[1]);
            next[a].push_back(b);
            next2[a].push_back(b);
            next2[b].push_back(a);
        }
        
        int ret = INT_MAX;
        for (int x=1; x<=n; x++)
        {
            for (int i=0; i<next[x].size(); i++)
                for (int j=i+1; j<next[x].size(); j++)
                {
                    int a = next[x][i];
                    int b = next[x][j];
                    if (c[a][b])
                        ret = min(ret, (int)next2[x].size()-2+(int)next2[a].size()-2+(int)next2[b].size()-2);
                }                
        }
        return ret==INT_MAX?-1:ret;        
    }
};
