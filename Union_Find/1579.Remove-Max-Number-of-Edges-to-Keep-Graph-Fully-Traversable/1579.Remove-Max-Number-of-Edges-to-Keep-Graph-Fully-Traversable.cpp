class Solution {    
    int N;
    int Father[100001];
    int Father0[100001];
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
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        N = n;
        
        vector<vector<int>>edge0;
        vector<vector<int>>edge1;
        vector<vector<int>>edge2;
        for (auto edge: edges)
        {
            if (edge[0]==3)
                edge0.push_back({edge[1],edge[2]});
            else if (edge[0]==1) 
                edge1.push_back({edge[1],edge[2]});
            else if (edge[0]==2) 
                edge2.push_back({edge[1],edge[2]});                
        }
        
        int count0 = 1, count1=0, count2=0;
                
        for (int i=0; i<N; i++)
            Father[i] = i;
        
        for (auto edge: edge0)
        {
            int a = edge[0];
            int b = edge[1];
            if (findFather(a)!=findFather(b))
            {
                Union(a,b);
                count0++;
            }
        }
        
        memcpy(Father0, Father, sizeof(Father));
        
        for (auto edge: edge1)
        {
            int a = edge[0];
            int b = edge[1];
            if (findFather(a)!=findFather(b))
            {
                Union(a,b);
                count1++;
            }
        }
        if (count0+count1!=n) return -1;
        
        memcpy(Father, Father0, sizeof(Father));
        
        for (auto edge: edge2)
        {
            int a = edge[0];
            int b = edge[1];
            if (findFather(a)!=findFather(b))
            {
                Union(a,b);
                count2++;
            }
        }
        if (count0+count2!=n) return -1;
        
        return edge0.size()-(count0-1) + edge1.size()-count1 + edge2.size()-count2;
    }
};
