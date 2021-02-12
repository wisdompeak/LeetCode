typedef pair<int,int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int, vector<PII>>Map;
        for (auto t: times)
            Map[t[0]].push_back({t[1], t[2]});

        vector<int>dist(n+1, INT_MAX);
        vector<bool>seen(n+1, 0);
        dist[k] = 0;
        
        for (int i=1; i<=n; i++)
        {
            int minVal = INT_MAX;
            int minNode = -1;
            for (int j=1; j<=n; j++)
            {
                if (!seen[j] && dist[j]<minVal)
                {
                    minVal = dist[j];
                    minNode = j;
                }
            }    
            if (minNode==-1) break;
            seen[minNode] = 1;        
            for (auto [next, d]: Map[minNode])
                dist[next] = min(dist[next], dist[minNode]+d);            
        }
        
        int ret = 0;
        for (int i=1; i<=n; i++)
            ret = max(ret, dist[i]);            

        return ret == INT_MAX ? -1: ret;
    }
};
