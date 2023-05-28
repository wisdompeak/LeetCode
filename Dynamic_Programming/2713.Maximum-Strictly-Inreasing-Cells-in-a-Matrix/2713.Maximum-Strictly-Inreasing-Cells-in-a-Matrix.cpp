using AI3 = array<int,3>;
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<AI3>nums;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                nums.push_back({mat[i][j], i, j});
        sort(nums.begin(), nums.end());

        vector<map<int,int>> rows(m);        
        vector<map<int,int>> cols(n);

        for (int i=0; i<m; i++)
            rows[i].insert({INT_MIN, 0});
        for (int j=0; j<n; j++)
            cols[j].insert({INT_MIN, 0});

        int ret = 1;
        for (auto [val, i, j]: nums)
        {
            int len = 1;

            auto iter = rows[i].lower_bound(val);
            iter = prev(iter);
            len = max(len, iter->second + 1);

            iter = cols[j].lower_bound(val);
            iter = prev(iter);
            len = max(len, iter->second + 1);

            rows[i][val] = max(len, rows[i][val]);
            cols[j][val] = max(len, cols[j][val]);

            ret = max(ret, len);
        }

        return ret;        
    }
};
