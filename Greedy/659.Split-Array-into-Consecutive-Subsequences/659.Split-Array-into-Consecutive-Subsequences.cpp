class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        vector<vector<int>>groups;
        
        for (int i=0; i<nums.size(); i++)
        {
            bool inserted=false;
            for (int j=groups.size()-1; j>=0; j--)
            {
                if (groups[j].size()>0 && nums[i]==groups[j].back()+1)
                {
                    groups[j].push_back(nums[i]);
                    inserted=true;
                    break;
                }
            }
            if (inserted==false)
            {
                groups.push_back({nums[i]});
            }
        }
        
        for (int i=0; i<groups.size(); i++)
        {
            if (groups[i].size()<3) 
                return false;
        }
        
        return true;
    }
};
