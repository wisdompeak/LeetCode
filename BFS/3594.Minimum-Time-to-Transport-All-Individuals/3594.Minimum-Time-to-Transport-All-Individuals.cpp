struct State {
    int mask, stage;
    double dist;
    bool operator<(State const& o) const {
        return dist > o.dist;
    }
};

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        vector<vector<double>>dist(1<<n, vector<double>(m, 1e300));
        priority_queue<State>pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0.0});
        int END = (1<<n)-1;

        while (!pq.empty()) {
            auto [mask, stage, d0] = pq.top();
            pq.pop();
            if (d0 > dist[mask][stage]) continue;
            if (mask==END) return d0;

            int rem = (~mask)&END;
            for (int sub = rem; sub>0; sub = (sub-1)&rem) {
                if (__builtin_popcount(sub)>k) continue;
                int mx = 0;
                for (int i=0; i<n; i++)
                    if (sub&(1<<i)) mx = max(mx, time[i]);
                double crossTime = mx*mul[stage];

                int stage2 = (stage + int(floor(crossTime)))%m;
                int mask2 = mask | sub;

                if (mask2 == END) {
                    if (d0+crossTime < dist[END][stage2]) {
                        dist[END][stage2] = d0+crossTime;
                        pq.push({END, stage2, d0+crossTime});
                    }
                } else {
                    for (int i=0; i<n; i++) {
                        if (!(mask2 & (1<<i))) continue;
                        double returnTime = time[i] * mul[stage2];
                        double dd = d0 + crossTime + returnTime;
                        int stage3 = (stage2 + int(floor(returnTime))) % m;
                        int mask3 = mask2 - (1<<i);
                        if (dd < dist[mask3][stage3]) {
                            dist[mask3][stage3] = dd;
                            pq.push({mask3, stage3, dd});
                        }                        
                    }
                }
            }            
        }
        return -1;
    }
};
