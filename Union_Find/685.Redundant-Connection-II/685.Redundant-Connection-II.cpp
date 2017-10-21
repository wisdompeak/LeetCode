class Solution {
    unordered_map<int,int>Father;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        vector<int>candA,candB;
        
        for (int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if (Father.find(v)==Father.end())
                Father[v]=u;
            else
            {
                candA={Father[v],v};
                candB=edges[i];
                break;
            }
        }
        
        for (int i=1; i<=edges.size(); i++)        
            Father[i]=i;    
        
        for (int i=0; i<edges.size(); i++)
        {
            if (edges[i]==candB) continue;
            
            int u=edges[i][0];
            int v=edges[i][1];
            
            if (findSet(v)==findSet(u))
            {
                if (candA.size()==0)
                    return edges[i];
                else
                    return candA;
            }
            else
                Father[v]=u;                
        }
        
        return candB;        
    }
    
	int	findSet(int x)
	{
		if (x!=Father[x])
			Father[x]=findSet(Father[x]);
		return Father[x];
	}    
};
