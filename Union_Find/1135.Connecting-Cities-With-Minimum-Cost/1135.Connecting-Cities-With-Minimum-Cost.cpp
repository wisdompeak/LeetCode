class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[2]<b[2];
    }
    vector<int>Father;
        
public:
    int findFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = findFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) 
    {
        Father.resize(N+1);
        for (int i=1; i<=N; i++)
            Father[i] = i;
        
        sort(connections.begin(), connections.end(), cmp);
        
        int result = 0;
        for (auto edge: connections)
        {
            int a = edge[0];
            int b = edge[1];
            if (findFather(a)!=findFather(b))
            {
                Union(a,b);
                result+=edge[2];
            }
        }
                
        for (int i=1; i<=N; i++)
        {
            if (findFather(i)!=Father[1])
                return -1;
        }
        
        return result;
    }
};
