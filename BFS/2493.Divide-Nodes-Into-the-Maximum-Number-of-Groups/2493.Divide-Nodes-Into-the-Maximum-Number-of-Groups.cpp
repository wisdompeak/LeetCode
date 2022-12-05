class Solution {
    int Father[505];
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
    
    vector<int>next[505];
    
public:
    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        for (int i=1; i<=n; i++)
            Father[i] = i;
        for (auto edge: edges)
        {
            int a = edge[0], b = edge[1];
            if (FindFather(a)!=FindFather(b))
                Union(a,b);
            next[a].push_back(b);
            next[b].push_back(a);
        }
        
        unordered_map<int,vector<int>>groups;
        for (int i=1; i<=n; i++)
            groups[FindFather(i)].push_back(i);
        
        int ret = 0;
        
        for (auto& [_, nodes]: groups)
        {            
            int ans = 0;
            for (int start: nodes)
            {                
                vector<int>level(505);
                level[start] = 1;
                queue<pair<int,int>>q;
                q.push({start, 1});
                
                while (!q.empty())
                {
                    auto [cur, d] = q.front();
                    q.pop();
                    ans = max(ans, d);
                                        
                    for (int nxt: next[cur])
                    {
                        if (level[nxt]==0)
                        {
                            level[nxt] = d+1;
                            q.push({nxt, d+1});
                        }
                        else if (level[nxt] == d)
                            return -1;                            
                    }
                }                
            }
            
            ret += ans;
        }
        
        return ret;
        
    }
};
