class Solution {
    vector<int>next [100005];
    int ans = 0;
    int n;
    vector<int> vals;
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        this->vals = vals;
        n = vals.size();
        for (auto& edge: edges)
        {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1);
        return ans + n;
    }
    
    map<int,int>dfs(int cur, int parent)
    {
        map<int,int>count;
        count[vals[cur]] += 1;
        
        for (int child: next[cur])
        {
            if (child == parent) continue;
            map<int,int> tmp = dfs(child, cur);
            
            auto iter = tmp.lower_bound(vals[cur]);
            tmp.erase(tmp.begin(), iter);
            
            if (tmp.size() > count.size())
                swap(tmp, count);
            
            for (auto& [val, frq]: tmp)
            {
                if (count.find(val)!=count.end())
                    ans += frq * count[val];
            }
            
            for (auto& [val, frq]: tmp)
                count[val] += frq;
        }
        
        return count;
    }
};
