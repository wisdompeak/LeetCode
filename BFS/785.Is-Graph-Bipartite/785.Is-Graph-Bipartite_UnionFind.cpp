class Solution {
    unordered_map<int,int>Father;
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int N=graph.size();
        for (int i=0; i<N; i++)
            Father[i]=i;
        for (int i=0; i<N; i++)
        {
            int k;
            if (graph[i].size()>0)
                k = graph[i][0];
            
            for (auto j:graph[i])
            {
                if (FindSet(i)==FindSet(j))
                    return false;                
                Union(k,j);
            }
        }
        
        return true;
    }
    
    int FindSet(int x)
    {
        if (x!=Father[x])
            Father[x]=FindSet(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x=Father[x];
        y=Father[y];
        if (x<y)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
