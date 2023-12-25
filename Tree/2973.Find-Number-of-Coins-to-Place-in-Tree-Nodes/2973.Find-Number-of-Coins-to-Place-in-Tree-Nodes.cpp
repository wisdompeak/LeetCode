using LL = long long;
class Solution {
    vector<int>next[20005];
    vector<int>children[20005];
    vector<LL>rets;
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }

        rets.resize(cost.size());
        dfs(0, -1, cost);  
        return rets;      
    }

    void dfs(int cur, int parent, vector<int>&cost)
    {
        vector<LL>temp;
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            dfs(nxt, cur, cost);
            for (int x:children[nxt])
                temp.push_back(x);
        }
        temp.push_back(cost[cur]);
        
        sort(temp.begin(), temp.end());
        int n = temp.size();
        if (n < 3)
           rets[cur] = 1;
        else
            rets[cur] = max(0LL, max(temp[n-3]*temp[n-2]*temp[n-1], temp[0]*temp[1]*temp[n-1]));
                
        if (n>=1) children[cur].push_back(temp[0]);
        if (n>=2) children[cur].push_back(temp[1]);
        if (n>=5) children[cur].push_back(temp[n-3]);
        if (n>=4) children[cur].push_back(temp[n-2]);
        if (n>=3) children[cur].push_back(temp[n-1]);
    }
};
