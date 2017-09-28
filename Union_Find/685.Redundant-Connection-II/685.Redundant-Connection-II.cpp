class Solution {
	unordered_map<int,int>Parent;
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
	{
        vector<int>candA,candB;
		
		for (int i=0; i<edges.size(); i++)
		{
			int u=edges[i][0];
			int v=edges[i][1];
			
			if (Parent.find(v)!=Parent.end())
			{
				candA={Parent[v],v};
				candB=edges[i];
				edges[i][1]=0;
                break;
			}
			else
				Parent[v]=u;
		}

		int n=edges.size();
		for (int i=1; i<=n; i++)
			Parent[i]=i;

		for (int i=0; i<edges.size(); i++)
		{
			if (edges[i][1]==0) continue;

			int u=edges[i][0];
			int v=edges[i][1];
			int pu=findRoot(u);
			if (pu==v)
			{
				if (candA.size()==0)
					return edges[i];
				else
					return candA;
			}
			Parent[v]=u;
		}
		return candB;	

    }

	int	findRoot(int x)
	{
		if (x!=Parent[x])
			Parent[x]=findRoot(Parent[x]);
		return Parent[x];
	}

};
