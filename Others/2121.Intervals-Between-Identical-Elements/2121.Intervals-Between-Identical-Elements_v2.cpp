class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> rets(n, 0);
        unordered_map<int, vector<int>> Map;

        for(int i = 0; i < arr.size(); ++i) {
            Map[arr[i]].push_back(i);
        }

        for(auto& [val, pos]: Map) {
            for(int x: pos) {
                rets[pos[0]] += x - pos[0];
            }

            for(int i = 1; i < pos.size(); ++i) {
                rets[pos[i]] = rets[pos[i-1]] + (pos[i] - pos[i-1]) * i - (pos[i] - pos[i-1]) * (pos.size() - i);
            }
        }

        return rets;
    }
};

// 0 1 2 3 4 5 6
// 2,1,3,1,2,3,3

// 1: 1 3
// 2: 0 4
// 3: 2 5 6

//      i        m - i
// {X X X i-1} {i X X X X}
