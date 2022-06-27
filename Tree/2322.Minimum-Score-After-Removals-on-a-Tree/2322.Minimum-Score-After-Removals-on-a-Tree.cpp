class Solution {    
    unordered_set<int> next[1005];  // next[i]:  a set of adjacent nodes next to i
    int visited[1005];
    vector<int>nums;
    int n;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        this->n = nums.size();
        this->nums = nums;
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].insert(b);
            next[b].insert(a);
        }
        
        int ret = INT_MAX;
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].erase(b);
            next[b].erase(a);
            
            int ret1 = solve(a, b);
            int ret2 = solve(b, a);
            
            ret = min(ret, min(ret1, ret2));
            
            next[a].insert(b);
            next[b].insert(a);
        }
        
        return ret;
    }
    
    int solve(int a, int b)
    {
        fill(visited, visited+n, 0);
        visited[a] = 1;
        int A = getAll(a);
        
        fill(visited, visited+n, 0);
        visited[b] = 1;
        int B = getAll(b);
        
        int ret = INT_MAX;
        fill(visited, visited+n, 0);
        visited[a] = 1;        
        dfs(a, ret, A, B);        
        return ret;
    }
    
    int dfs(int node, int& ret, int A, int B)
    {
        int total = 0;
        for (int nxt: next[node])
        {
            if (visited[nxt]==1) continue;
            visited[nxt] = 1;
            
            int C = dfs(nxt, ret, A, B);
            int other = A^C;
            int mx = max(other, max(C, B));
            int mn = min(other, min(C, B));
            ret = min(ret, mx-mn);
            
            total^=C;
        }
        total ^= nums[node];
        return total;
    }
    
    int getAll(int node)
    {
        int total = 0;
        for (int nxt: next[node])
        {
            if (visited[nxt]==1) continue;
            visited[nxt] = 1;
            total ^= getAll(nxt);
        }
        total ^= nums[node];
        return total;
    }       
    
};
