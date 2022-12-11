class Solution {
    int ret = 0;
    unordered_map<int,int>Map;
public:
    int numberOfNodes(int n, vector<int>& queries) 
    {        
        for (int q: queries)
            Map[q]++;
        dfs(1,0,n);
        return ret;        
    }

    void dfs(int cur, int flips, int n)
    {
        if (cur > n) return;

        if (Map.find(cur)!=Map.end())
            flips += Map[cur];
        if (flips%2==1)
            ret++;

        dfs(cur*2, flips, n);
        dfs(cur*2+1, flips, n);
    }
};
