class Solution {
    vector<vector<int>>rets;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int>comb = {};
        DFS(candidates, target, 0, 0, comb);
        return rets;
    }
    
    void DFS(vector<int>& candidates, int target, int idx, int sum, vector<int>&comb)
    {
        if (target==sum)
        {
            rets.push_back(comb);
            return;
        }
        if (sum>target)
        {
            return;
        }
        
        for (int i=idx; i<candidates.size(); i++)
        {
            if (i>idx && candidates[i]==candidates[i-1])
                continue;
            
            comb.push_back(candidates[i]);
            DFS(candidates, target, i+1, sum+candidates[i], comb);
            comb.pop_back();
        }
    }
};
