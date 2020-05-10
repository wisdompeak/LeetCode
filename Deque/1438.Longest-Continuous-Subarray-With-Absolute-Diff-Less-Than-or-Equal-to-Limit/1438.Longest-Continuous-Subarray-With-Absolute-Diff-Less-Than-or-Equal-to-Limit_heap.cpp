class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        multiset<int>Set;
        int j = 0;
        int ret = 0;        
        
        for (int i=0; i<nums.size(); i++)
        {            
            while (j<nums.size() && (Set.size()==0 || *Set.rbegin()-*Set.begin()<=limit))
            {
                Set.insert(nums[j]);
                j++;
            }
            
            if (*Set.rbegin()-*Set.begin()>limit) 
            {
                j--;
                Set.erase(Set.find(nums[j]));
            }

            ret = max(ret, (int)Set.size());
                                    
            if (i>=0) Set.erase(Set.find(nums[i]));     

        }
        
        return ret;
        
    }
};
