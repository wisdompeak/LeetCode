class Solution {
    vector<int>nums;
    vector<vector<int>>edges;
    vector<int>Map[100000];
    vector<int>next[100000];
    vector<int>path;
    vector<int>ret;
    int visited[100000];
        
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) 
    {
        this->nums = nums;
        this->edges = edges;        
        int n = nums.size();
        ret.resize(n);
        
        for (auto e: edges)
        {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        visited[0] = 1;
        ret[0] = -1;
        dfs(0, 0);
        return ret;
    }
    
    void dfs(int cur, int depth)
    {
        if (depth>0)
        {
            int ans = -1;
            for (int d=1; d<=50; d++)
            {
                if (Map[d].size()>0 && gcd(d, nums[cur])==1)
                    ans = max(ans, Map[d].back());
            }
            if (ans!=-1) ret[cur] = path[ans];
            else ret[cur] = -1;
        }
        
        path.push_back(cur);
        Map[nums[cur]].push_back(depth);
        for (auto x: next[cur])
        {
            if (visited[x]) continue;
            visited[x] = 1;
            dfs(x, depth+1);            
            visited[x] = 0;
        }
        path.pop_back();
        Map[nums[cur]].pop_back();        
    }
};
