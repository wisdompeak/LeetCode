class DistanceLimitedPathsExist {
    vector<pair<int,int>> snaps[10000];
    int father[10000];
    int rank[10000];
    vector<int>dist;
    unordered_set<int>changed;
    int snapId = 0;
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) 
    {
        for (int i=0; i<n; i++)
        {
            snaps[i].push_back({-1, i});
            father[i] = i;
        }            
                
        sort(edgeList.begin(),edgeList.end(), [](auto const &a,auto const &b) { return a[2] < b[2]; });
        
        int cur_dist = 0;
        for (auto e: edgeList)
        {
            if (e[2] > cur_dist) 
            {
                dist.push_back(cur_dist);
                cur_dist = e[2];
                for (auto node: changed)
                {
                    snaps[node].push_back({snapId, father[node]});
                }
                changed.clear();
                snapId++;
            }
            int a = e[0], b = e[1];
            Union(a,b);            
        }
    }
    
    int findFather(int node)
    {
        while (father[node]!=node)
            node = father[node];
        return node;
    }
    
    void Union(int a, int b)
    {
        a = findFather(a);
        b = findFather(b);
        if (findFather(a)!=findFather(b))
        {
            if (rank[a]<rank[b])
            {
                father[a] = b;
                rank[b] = max(rank[b], rank[a]+1);
                changed.insert(a);
            }
            else
            {
                father[b] = a;
                rank[a] = max(rank[a], rank[b]+1);
                changed.insert(b);
            }
        }            
    }
    
    int findSnapFather(int node, int snap_id)
    {
        auto iter = upper_bound(snaps[node].begin(), snaps[node].end(), make_pair(snap_id, INT_MAX));
        iter = prev(iter,1);
        int f = iter->second;
        if (f==node)
            return f;
        else
            return findSnapFather(f, snap_id);        
    }
    
    bool query(int p, int q, int limit) 
    {
        int snap_id = lower_bound(dist.begin(), dist.end(), limit) - dist.begin() - 1;
        return findSnapFather(p, snap_id)==findSnapFather(q, snap_id);
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */
