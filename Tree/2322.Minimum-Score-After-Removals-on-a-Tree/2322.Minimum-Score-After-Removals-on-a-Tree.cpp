class Solution {
    unordered_set<int> next[1000];
    vector<int>nums;
    vector<int>visited;
    int n;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        this->nums = nums;
        this->n = nums.size();
        visited.resize(n);
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].insert(b);
            next[b].insert(a);
        }
        
        int ret = INT_MAX;
        for (int i=0; i<edges.size(); i++)
        {
            int a = edges[i][0], b = edges[i][1];
            next[a].erase(b);
            next[b].erase(a);

            int ret1 = solve(a, b);
            int ret2 = solve(b, a);

            next[a].insert(b);
            next[b].insert(a);

            ret = min(ret, min(ret1, ret2));                        
        }            
        return ret;        
    }
    
    int solve(int a, int b)
    {
        fill(visited.begin(), visited.end(), 0);
        visited[a] = 1;
        int x = getAll(a);
        
        fill(visited.begin(), visited.end(), 0);
        visited[b] = 1;
        int y = getAll(b);
                
        int ret = INT_MAX;        
        fill(visited.begin(), visited.end(), 0);
        visited[a] = 1;
        dfs(a, ret, x, y);
        return ret;
    }
    
    int dfs(int cur, int& ret, int x, int y)
    {  
        int total = 0;
        for (int nxt: next[cur]) 
        {
           if (visited[nxt]==1) continue;
           visited[nxt] = 1;
            
           int branch = dfs(nxt, ret, x, y);
           int other = x^branch;
           int mx = max(branch, max(other, y));
           int mn = min(branch, min(other, y));
           ret = min(ret, mx-mn);
            
           total ^= branch;
        }
        total^=nums[cur];
        return total;
    }
    
    int getAll(int cur)
    {
        int total = 0;        
        for (int nxt: next[cur])
        {
            if (visited[nxt]==1) continue;
            visited[nxt] = 1;
            total ^= getAll(nxt);            
        }            
        total ^= nums[cur];
        return total;
    }    
};
