typedef pair<int,int> PII;
class Solution {
    vector<PII> next[20001];
    int dist[20001];
    int visited[20001];
    long path[20001];
    long M = 1e9+7;
    int n;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        this-> n = n;
        for (auto e:edges)
        {
            int a = e[0]-1;
            int b = e[1]-1;
            next[a].push_back({b, e[2]});
            next[b].push_back({a, e[2]});
        }
        
        for (int i=0; i<n; i++)
            path[i] = -1;
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0, n-1});
                
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            if (visited[cur]==1) continue;
            visited[cur] = 1;
            dist[cur] = d;
            
            for (auto [nxt, len] :next[cur])
            {
                if (visited[nxt]==1) continue;
                pq.push({d+len, nxt});
            }
        }

        long ret = dfs(0);
        return ret;
    }
    
    long dfs(int cur)
    {
        if (cur==n-1)
            return 1;        
        if (path[cur]!=-1)
            return path[cur];
        long sum = 0;
        for (auto [nxt, len]: next[cur])
        {
            if (dist[nxt]>=dist[cur]) continue;
            visited2[nxt] = 1;
            sum += dfs(nxt);
            sum %= M;
        }
        path[cur] = sum;
        return sum;
    }
    
};
