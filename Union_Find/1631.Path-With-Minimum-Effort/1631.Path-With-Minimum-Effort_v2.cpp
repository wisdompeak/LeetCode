class Solution {
    int Father[10001];
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
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size();
        int n = heights[0].size();
        for (int i=0; i<m*n; i++)
            Father[i] = i;
        
        vector<vector<int>>q;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (i!=m-1) q.push_back({abs(heights[i][j]-heights[i+1][j]),i*n+j,(i+1)*n+j});
                if (j!=n-1) q.push_back({abs(heights[i][j]-heights[i][j+1]),i*n+j,i*n+j+1});
            }
        sort(q.begin(), q.end());
        
        for (auto x:q)
        {
            if (FindFather(x[1])!=FindFather(x[2]))
                Union(x[1],x[2]);
            if (FindFather(0)==FindFather((m-1)*n+n-1))
                return x[0];
        }
        return 0;
    }
};
