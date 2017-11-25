class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>>results;
        vector<int>curRes;
        DFS(nums,0,curRes,results);
        return results;
    }
    
    void DFS(vector<int>& nums, int idx, vector<int>&curRes, vector<vector<int>>&results)
    {
        if (curRes.size()>1) results.push_back(curRes);                
        if (idx==nums.size()) return;                

        unordered_set<int>Set;
        for (int i=idx; i<nums.size(); i++)
        {            
            if (curRes.size()!=0 && nums[i]<curRes.back() ) continue;
            if (Set.find(nums[i])!=Set.end()) continue;            
            Set.insert(nums[i]);
            
            curRes.push_back(nums[i]);
            DFS(nums,i+1,curRes,results);
            curRes.pop_back();                        
        }
    }
};
