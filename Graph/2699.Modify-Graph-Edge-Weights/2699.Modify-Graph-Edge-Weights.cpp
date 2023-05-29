using PII = pair<int,int>;
class Solution {
    unordered_map<int,int> next[105];
    int todo[105][105];
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) 
    {
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1], c=edge[2];
            if (c==-1) 
            {
                c = 1;
                todo[a][b] = 1;
                todo[b][a] = 1;
            }
            next[a][b] = c;
            next[b][a] = c;
        }
        
        priority_queue<PII, vector<PII>, greater<>>pq;
        vector<int>dist1(n, INT_MAX/3);

        pq.push({0, destination});
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            if (dist1[cur]!=INT_MAX/3) continue;
            dist1[cur] = d;
            for (auto [nxt, weight]: next[cur])
            {
                if (dist1[nxt]!=INT_MAX/3) continue;
                pq.push({d+weight, nxt});
            }
        }
            

        vector<int>dist(n, INT_MAX/3);
        pq.push({0, source});
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            if (dist[cur]!=INT_MAX/3) continue;
            dist[cur] = d;
            if (cur==destination && d != target) return {};
            for (auto [nxt, weight]: next[cur])
            {
                if (dist[nxt]!=INT_MAX/3) continue;
                if (todo[cur][nxt]==1 && dist[cur]+weight+dist1[nxt] < target)                
                {
                    weight = target-dist[cur]-dist1[nxt];
                    next[cur][nxt] = weight;
                    next[nxt][cur] = weight;                    
                }
                pq.push({d+weight, nxt});
            }
        }

        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];            
            edge[2] = next[a][b];
        }

        return edges;
    }
};
