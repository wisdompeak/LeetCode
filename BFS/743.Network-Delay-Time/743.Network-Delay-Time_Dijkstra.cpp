typedef pair<int,int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int, vector<PII>>Map;
        for (auto t: times)
            Map[t[0]].push_back({t[1], t[2]});


        priority_queue<PII, vector<PII>, greater<>>pq;
        pq.push({0,k});
        vector<int>visited(n+1,0);
        
        int ret = 0;
        while (!pq.empty())
        {
            auto [d, cur] = pq.top();
            pq.pop();
            ret = max(ret, d);

            if (visited[cur]) continue;
            visited[cur] = 1;
            
            for (auto next: Map[cur])
                pq.push({d+next.second, next.first});
        }

        for (int i=1; i<=n; i++)
            if (visited[i]==0) return -1;

        return ret;
    }
};
