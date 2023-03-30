class Solution {
public:
    vector<int> fallingSquares(vector <vector<int>> &positions) {
        map<int, int> Map;

        Map[0] = 0;
        Map[INT_MAX] = 0;

        vector<int> results;
        int cur = 0;

        for (auto p: positions) {
            int left = p[0];
            int right = p[0] + p[1] - 1;
            int h = p[1];
            int maxH = 0;

            auto ptri = Map.lower_bound(left);
            auto ptrj = Map.upper_bound(right);

            int temp = prev(ptrj, 1)->second;

            auto ptr = ptri->first == left ? ptri : prev(ptri, 1);
            while (ptr != ptrj) {
                maxH = max(maxH, ptr->second);
                ptr = next(ptr, 1);
            }
            if (ptri != ptrj)
                Map.erase(ptri, ptrj);

            Map[left] = maxH + h;
            if (right + 1 < ptrj->first)
                Map[right + 1] = temp;
            cur = max(cur, maxH + h);

            results.push_back(cur);
        }

        return results;

    }
};
