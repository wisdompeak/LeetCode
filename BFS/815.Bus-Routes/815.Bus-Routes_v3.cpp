class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return false;
        int nSets = routes.size();
        unordered_map<int, vector<int>> stop2sets;

        for(int i = 0; i < nSets; ++i) {
            for(auto x: routes[i]) {
                stop2sets[x].push_back(i);
            }
        }

        vector<vector<int>> graph(nSets);  // relation between graph sets
        vector<vector<int>> dp(nSets, vector<int>(nSets, INT_MAX / 2));

        // n^3: 500^3 = 125e6
        // if in the same stop set, takes at most 0 bus
        // if source and target are the same, should return 0
        for(int i = 0; i < nSets; ++i) {
            dp[i][i] = 0;
        } 

        // if with a stop joint, it takes at most 1 bus
        for(auto it = stop2sets.begin(); it != stop2sets.end(); ++it) {
            auto& v = it->second;

            for(int i = 0; i < v.size(); ++i) {
                for(int j = i + 1; j < v.size(); ++j) {
                    graph[v[i]].push_back(v[j]);
                    graph[v[j]].push_back(v[i]);
                    dp[v[i]][v[j]] = min(dp[v[i]][v[j]], 1);
                    dp[v[j]][v[i]] = min(dp[v[j]][v[i]], 1);
                }
            }
        }

        auto& ss1 = stop2sets[source];  // stopset1
        auto& ss2 = stop2sets[target];  // stopset2
        for(int len = 1; len < nSets; ++len) {
            for(int x = 0; x < nSets - len; ++len) {
                for(int len2 = 1; len2 < len; ++len2) {
                    dp[x][x+len] = min(dp[x][x+len], dp[x][x+len2] + dp[x+len2][x+len]);
                    dp[x+len][x] = dp[x][x+len];
                }
            }
        }

        int ret = INT_MAX;
        for(auto x: ss1) {
            for(auto y: ss2) {
                ret = min(dp[x][y], ret);
            }
        }

        return ret > 1e8 ? -1: (ret+1); // it takes one step from the stop to the joint
    }
};

// treat each bus connected stops sets as a node in a graph
// routes between stop sets, map: stop -> set of stops
// two stops sets are interconntected when the stop sets of them have common stops
// Shortest path from source to target, is the shortest path from the sets that includes source and the sets that includes the target
// dp[i][j]: shortest distance between stop set i and stop set j
