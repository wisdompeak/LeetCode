class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<int>perm;
        DFS(perm,0,nums);
        return results;
    }
    
    void DFS(vector<int>perm, int k, vector<int>& nums)
    {
        if (k==nums.size())
        {
            results.push_back(perm);
            return;
        }
        
        for (int i=0; i<k+1; i++)
        {
            vector<int>newPerm = perm;
            if (i==0 || i>=1 && nums[k]!=perm[i-1])
            {
                newPerm.insert(newPerm.begin()+i, nums[k]);
                DFS(newPerm, k+1, nums);
            }
            else
                return;            
        }
            
    }
};
