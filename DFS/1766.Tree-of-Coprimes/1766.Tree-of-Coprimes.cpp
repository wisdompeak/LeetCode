class Solution {
    vector<int> path; // path[i] is the i-th node idx along the dfs path
    vector<int> records[51]; // records[i] contains the depths of all the nodes whose num = i
    vector<int> rets;
    vector<int> next[100000];
    int visited[100000];
    vector<int>nums;
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) 
    {
        this->nums = nums;
        int n = nums.size();
        rets.resize(n);
        
        for (auto e:edges)
        {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        visited[0] = 1;
        dfs(0, 0);
        return rets;
    }
    
    void dfs(int curIdx, int depth)
    {
        int i = -1;
        for (int d=1; d<=50; d++)
        {
            if (records[d].size() > 0 && gcd(d, nums[curIdx])==1)
            {
                i = max(i, records[d].back());
            }
        }
        rets[curIdx] = (i==-1) ? -1 : path[i];
        
        path.push_back(curIdx);
        records[nums[curIdx]].push_back(depth);                        
        
        for (int nextIdx : next[curIdx])
        {
            if (visited[nextIdx]) continue;
            visited[nextIdx] = 1;
            dfs(nextIdx, depth+1);
            visited[nextIdx] = 0;
        }
        
        path.pop_back();
        records[nums[curIdx]].pop_back();                        
    }
};
