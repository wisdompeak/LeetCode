class Solution {
    vector<vector<int>>results;
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int>curRes;
        DFS(nums,0,curRes);
        return results;
    }
    
    void DFS(vector<int>& nums, int start, vector<int>curRes)
    {
        if (curRes.size()>1) results.push_back(curRes);
        
        if (start>=nums.size()) return;

        unordered_set<int>visited;        
        for (int i=start; i<nums.size(); i++)
        {
            if (start>0 && nums[i]<curRes.back()) continue;
            if (visited.find(nums[i])!=visited.end()) continue;
            visited.insert(nums[i]);
            
            curRes.push_back(nums[i]);
            DFS(nums,i+1,curRes);
            curRes.pop_back();
        }
    }
};
