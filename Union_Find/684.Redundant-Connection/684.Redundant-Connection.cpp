class Solution {
    unordered_map<int,int>Father;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {        
        for (int i=0; i<edges.size(); i++)
        {
            Father[edges[i][0]]=edges[i][0];
            Father[edges[i][1]]=edges[i][1];
        }
        
        for (int i=0; i<edges.size(); i++)
        {
            if (FindSet(edges[i][0])==FindSet(edges[i][1]))
                return edges[i];
            else
                Union(edges[i][0],edges[i][1]);
        }
        return edges[0];
    }
    
    int FindSet(int x)
    {
        if (x!=Father[x])
        {
            Father[x]=FindSet(Father[x]);
        }
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x=FindSet(x);
        y=FindSet(y);
        if (x<=y)
            Father[y]=x;
        else
            Father[x]=y;
    }
};
