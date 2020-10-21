class Solution {
    vector<int>Father;
public:
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) 
    {
        Father.resize(n+1);
        for (int i=1; i<=n; i++)
            Father[i] = i;
        
        vector<int>visited(n+1,0);
        for (int k = threshold + 1; k <= n; k++) 
        {
            if (visited[k]==1) continue;
            for (int x = 2 * k; x <= n; x += k) 
            {
                visited[x] = 1;
                if (FindFather(x)!=FindFather(k))
                    Union(x, k);
            }
        }
        
        vector<bool>rets;
        for (auto query: queries)
            rets.push_back(FindFather(query[0])==FindFather(query[1]));
        return rets;
        
    }
};
