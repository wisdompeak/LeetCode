using AI3 = array<int,3>;
using PII = pair<int,int>;
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<map<int,int>>rows(m);
        vector<map<int,int>>cols(n);
        vector<AI3>nums;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)            
                nums.push_back({mat[i][j], i, j});                
        
        for (int i=0; i<m; i++)
            rows[i].insert({INT_MIN, 0});
        for (int j=0; j<n; j++)
            cols[j].insert({INT_MIN, 0});
                
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (auto [val, i, j]: nums)
        {
            int ret = 1;
            auto iter = rows[i].lower_bound(val);
            ret = max(ret, prev(iter)->second + 1);
            
            iter = cols[j].lower_bound(val);
            ret = max(ret, prev(iter)->second + 1);
                            
            rows[i][val] = max(rows[i][val], ret);
            cols[j][val] = max(cols[j][val], ret);
            
            ans = max(ans, ret);                 
        }
        
        return ans;
        
    }
};
