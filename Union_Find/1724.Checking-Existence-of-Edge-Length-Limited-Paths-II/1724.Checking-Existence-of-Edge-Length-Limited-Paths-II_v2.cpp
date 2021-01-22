class DistanceLimitedPathsExist {
    vector<pair<int,int>> snaps[10000];
    int father[10000];
    int rank[10000];
    unordered_set<int>changed; // the nodes whose father has been modified since last snapshot    
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) 
    {
        for (int i=0; i<n; i++)
        {
            father[i] = i;
            snaps[i].push_back({0, i});
        }
        
        sort(edgeList.begin(), edgeList.end(), [](auto const&a, auto const&b){return a[2]<b[2];});
        int curLen = 0;
        for (auto e: edgeList)
        {
            if (e[2] > curLen)
            {                
                for (auto node: changed)
                {
                    snaps[node].push_back({curLen, father[node]});
                }
                changed.clear();                
                curLen = e[2];
            }
            Union(e[0], e[1]);
        }        
    }
    
    int findFather(int a)
    {
        while (father[a]!=a)
            a = father[a];
        return a;
    }
        
    void Union(int a, int b)
    {
        int fa = findFather(a);
        int fb = findFather(b);
        if (fa!=fb)
        {
            if (rank[fa] < rank[fb])
            {
                father[fa] = fb;
                rank[fb] = max(rank[fb], rank[fa]+1);
                changed.insert(fa);
            }
            else
            {
                father[fb] = fa;
                rank[fa] = max(rank[fa], rank[fb]+1);
                changed.insert(fb);
            }
        }
    }
    
    int findSnapRoot(int node, int limit)
    {
        auto iter = lower_bound(snaps[node].begin(), snaps[node].end(), make_pair(limit, 0));
        iter = prev(iter,1);
        int f = iter->second;
        if (f==node)
            return f;
        else
            return findSnapRoot(f, limit);
    }
    
    bool query(int p, int q, int limit) 
    {
        return findSnapRoot(p, limit) == findSnapRoot(q, limit);
    }
};
