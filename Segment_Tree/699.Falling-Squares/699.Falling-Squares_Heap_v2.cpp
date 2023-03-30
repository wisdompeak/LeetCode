class Solution {
public:
    vector<int> fallingSquares(vector <vector<int>> &positions) {
        map<int, int> Map;
        Map[0] = 0;
        Map[INT_MAX] = 0;
        int cur = 0;
        vector<int> results;

        for (int i = 0; i < positions.size(); i++) {
            int left = positions[i][0];
            int len = positions[i][1];
            int right = left + len - 1;

            auto pos1 = Map.lower_bound(left);

            int Hmax = 0;
            auto pos = pos1;
            if (pos->first != left) pos = prev(pos, 1);
            while (pos->first <= right) {
                Hmax = max(Hmax, pos->second);
                pos = next(pos, 1);
            }
            int rightHeight = prev(pos, 1)->second;

            Map.erase(pos1, pos);
            Map[left] = Hmax + len;
            if (right + 1 < pos->first)
                Map[right + 1] = rightHeight;

            cur = max(cur, Hmax + len);
            results.push_back(cur);
        }

        return results;
    }
};
