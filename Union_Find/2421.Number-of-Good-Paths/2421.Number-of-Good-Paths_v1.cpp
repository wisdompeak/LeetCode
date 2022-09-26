class Solution {
    vector<int>Father;
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
        if (x<y) Father[y] = x;
        else Father[x] = y;
    } 
    
public:
    vector<pair<int,int>>e [100005];
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n = vals.size();
        Father.resize(n);
        for (int i=0; i<n; i++)
            Father[i] = i;
        
        unordered_map<int, vector<int>>val2idx;
        for (int i=0; i<n; i++)
            val2idx[vals[i]].push_back(i);
                                
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            if (vals[a] < vals[b])
                swap(a,b);
            e[vals[a]].push_back({a,b});
        }
        
        int ret = 0;
        
        set<int>ValSet(vals.begin(), vals.end());        
        for (int v: ValSet)
        {
            for (auto& [v,x]: e[v])
            {
                if (FindFather(v)!=FindFather(x))
                    Union(v,x);
            }
            
            unordered_map<int,int>count;            
            for (auto idx: val2idx[v])
            {
                int root = FindFather(idx);
                count[root]++;
            }
            
            for (auto& [v, num]: count)
                ret += num*(num-1)/2;
        }
        
        return ret + n;
        
    }
};
