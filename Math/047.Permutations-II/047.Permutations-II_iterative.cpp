class Solution {
public:    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>perm({{}});
        vector<vector<int>>perm2;
        for (int k=0; k<nums.size(); k++)
        {
            perm2.clear();
            for (auto p: perm)
            {
                for (int i=0; i<=k; i++)
                {
                    vector<int> t = p;
                    t.insert(t.begin()+i, nums[k]);
                    perm2.push_back(t);
                    if (i<p.size() && nums[k]==p[i])
                        break;                    
                }
            }
            swap(perm, perm2);
        }
        
        return perm;
    }

};
