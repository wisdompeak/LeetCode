class Solution {
    int dp[100005][2];
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>>r;
        for (int i=0; i<n; i++)
            r.push_back({robots[i], distance[i]});        
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());

        auto shoot = [&](int i, int dir){
            if (dir==0) {
                auto iter1 = lower_bound(walls.begin(), walls.end(), max(i==0?INT_MIN:r[i-1].first+1, r[i].first-r[i].second));
                auto iter2 = upper_bound(walls.begin(), walls.end(), r[i].first);                
                return iter2 - iter1;
            } else {
                auto iter1 = lower_bound(walls.begin(), walls.end(), r[i].first);
                auto iter2 = upper_bound(walls.begin(), walls.end(), min(i==n-1?INT_MAX:r[i+1].first-1, r[i].first+r[i].second));
                return iter2 - iter1;
            }
        };

        auto overlap = [&](int i){            
            auto iter1 = lower_bound(walls.begin(), walls.end(), r[i-1].first);
            auto iter2 = upper_bound(walls.begin(), walls.end(), r[i].first);
            int overlap = shoot(i, 0) + shoot(i-1, 1) - (int)(iter2-iter1);
            return max(overlap, 0);
        };

        dp[0][0] = shoot(0, 0);
        dp[0][1] = shoot(0, 1);
        for (int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][1]+shoot(i,0)-overlap(i), dp[i-1][0]+shoot(i,0));            
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + shoot(i,1);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
