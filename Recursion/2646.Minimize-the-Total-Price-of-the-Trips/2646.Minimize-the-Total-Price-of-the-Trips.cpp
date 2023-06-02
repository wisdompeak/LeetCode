class Solution {
    vector<int>next[55];
    int n;
    int count[55];
    int plan0[55];
    int plan1[55];
    int val[55];
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        for (int i=0; i<n; i++)
        {
            plan0[i] = -1;
            plan1[i] = -1;
        }
        
        for (auto& trip: trips)
        {
            dfs(trip[0], -1, trip[1]);
        }
        
        for (int i=0; i<n; i++)
        {
            val[i] = price[i]*count[i];
        }
        
        return DFS(0, -1, 1);
    }
    
    bool dfs(int cur, int parent, int target)
    {        
        if (cur==target) 
        {
            count[cur]++;
            return true;
        }            
        
        for (int x: next[cur])
        {
            if (x==parent) continue;
            if (dfs(x, cur, target))
            {
                count[cur]++;
                return true;                
            }                
        }
        return false;
    }
    
    int DFS(int node, int parent, int flag)  // flag = 1 : can choose;  flag = 0 : cannot choose 
    {                
        if (flag==0 && plan0[node]!=-1) return plan0[node];
        if (flag==1 && plan1[node]!=-1) return plan1[node];        
                
        if (flag==0)
        {
            int ret = val[node];
            for (int x: next[node])
            {
                if (x==parent) continue;
                ret += DFS(x, node, 1);
            }        
            plan0[node] = ret;
            return ret;
        }
        else
        {
            int ret = INT_MAX;
            int option1 = val[node]/2;
            for (int x: next[node])
            {
                if (x==parent) continue;
                option1 += DFS(x, node, 0);
            }
            
            int option2 = val[node];
            for (int x: next[node])
            {
                if (x==parent) continue;
                option2 += DFS(x, node, 1);
            }
                        
            ret = min(option1, option2);
            plan1[node] = ret;
            return ret;
        }                
    }
};
