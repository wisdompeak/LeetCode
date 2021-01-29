class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        multiset<int>Set(nums.begin(),nums.end());
        while (Set.size()>0)
        {
            int a = *(Set.begin());
            for (int i=0; i<k; i++)
            {
                if (Set.find(a+i)==Set.end())
                    return false;
                Set.erase(Set.lower_bound(a+i));
            }            
        }
        return true;        
    }
};
