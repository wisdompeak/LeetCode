class Solution {
    vector<pair<int,int>> next[10005];
    int count[10005][27];
    int parent[10005];
    int level[10005];
    int ancestor[10005][18];
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1], c = edge[2];
            next[a].push_back({b,c});
            next[b].push_back({a,c});
        }
        
        vector<int>temp(27);
        dfs(0, 0, -1, temp);
        parent[0] = -1;

        for (int i=0; i<n; i++)
            ancestor[i][0] = parent[i];
        ancestor[0][0] = 0;
        int M = ceil(log(n)/log(2));
        for (int j=1; j<=M; j++)
            for (int i=0; i<n; i++)
                ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        
        vector<int>rets;        
        for (auto query: queries)
        {
            int a = query[0], b = query[1];
            // int lca = getLCA(0,a,b);
            int lca = getLCA(a,b);
            
            vector<int>temp(27);
            for (int i=1; i<=26; i++)
            {
                temp[i] += count[a][i];
                temp[i] += count[b][i];
                temp[i] -= 2*count[lca][i];
            }
            
            int sum = 0;
            int mx = 0;
            for (int i=1; i<=26; i++)
            {
                sum += temp[i];
                mx = max(mx, temp[i]);
            }
            
            rets.push_back(sum - mx);
        }
        
        return rets;
    }
    
    void dfs(int cur, int l, int p, vector<int>&temp)
    {
        for (auto& child: next[cur])
        {
            if (child.first==p) continue;
            int w = child.second;
            
            temp[w]+=1;
            for (int i=1; i<=26; i++)
                count[child.first][i] = temp[i];
            
            parent[child.first] = cur;
            level[child.first] = l+1;
            
            dfs(child.first, l+1, cur, temp);
            temp[w]-=1;
        }
    }
      
    int getKthAncestor(int i, int k)
    {
        int cur = i;
        for (int j=0; j<=17; j++)
        {
            if ((k>>j)&1)            
                cur = ancestor[cur][j];            
        }
        return cur;
    }

    int getLCA(int a, int b)
    {
        while (level[a]!=level[b])
        {
            if (level[a]<level[b])
                b = getKthAncestor(b, level[b]-level[a]);
            else
                a = getKthAncestor(a, level[a]-level[b]);
        }
        int left = 0, right = level[a];
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (getKthAncestor(a, mid)==getKthAncestor(b,mid))
                right = mid;
            else
                left = mid+1;
        }
        return getKthAncestor(a, left);
    }
};
