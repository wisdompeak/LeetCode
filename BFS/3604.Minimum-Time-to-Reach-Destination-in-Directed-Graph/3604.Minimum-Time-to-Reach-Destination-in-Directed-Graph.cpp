struct state {
    int node, time;
    bool operator<(state const& o) const {
        return time > o.time;
    }
};
class Solution {
    vector<vector<int>>next[100005];
public:
    int minTime(int n, vector<vector<int>>& edges) {
        for (auto& e:edges) {
            int u=e[0], v=e[1], start=e[2], end=e[3];
            next[u].push_back({v, start, end});
        }

        vector<int>visited(n, -1);
        priority_queue<state>pq;
        pq.push({0,0});

        while (!pq.empty()) {
            auto [node, time] = pq.top();
            // cout<<node<<" "<<time<<endl;
            pq.pop();
            if (visited[node]!=-1) continue;
            visited[node] = time;
            if (node==n-1) return time;

            for (auto nxt: next[node]) {
                int v = nxt[0], s = nxt[1], e = nxt[2];
                if (time < s && (visited[v]==-1 || visited[v]>s+1)) {
                    pq.push({v, s+1});
                }
                if (time >= s && time <=e && (visited[v]==-1 || visited[v]>time+1)) {
                    pq.push({v, time+1});
                }
            }
        }

        return -1;        
    }
};
