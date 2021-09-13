class Solution {    
    unordered_set<int>Set;
    vector<int>children[100001];
    int q = 1;
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) 
    {
        int n = parents.size();                
        for (int i=1; i<n; i++)
        {
            if (parents[i]!=-1)
                children[parents[i]].push_back(i);
        }
        
        vector<int>val2node(100001, -1);
        vector<int>rets(n, 1);
        
        for (int i=0; i<n; i++)
            val2node[nums[i]] = i;
        
        if (val2node[1]==-1)
            return rets;
        
        int node = val2node[1];
        for (int child: children[node])
            dfs1(child, rets);                        
        while (node!=0)
        {
            int p = parents[node];
            for (int child: children[p])
            {
                if (child!=node)
                    dfs1(child, rets);
            }
            node = p;
        }
                                
        node = val2node[1];
        while (node!=-1)
        {
            dfs(node, nums);                            
            while (Set.find(q)!=Set.end())
                q++;
            rets[node] = q;
            node = parents[node];
        }
        
        return rets;        
    }
    
    void dfs1(int node, vector<int>&rets)
    {
        rets[node] = 1;    
        for (auto child: children[node])        
            dfs1(child, rets);                
    }
    
    void dfs(int node, vector<int>&nums)
    {
        if (Set.find(nums[node])!=Set.end()) return;        
        Set.insert(nums[node]);
        for (int child: children[node])
            dfs(child, nums);
    }
};
