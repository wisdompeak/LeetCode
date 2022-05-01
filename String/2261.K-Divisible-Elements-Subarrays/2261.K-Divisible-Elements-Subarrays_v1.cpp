class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        int ret = 0;
        
        for (int len=1; len<=nums.size(); len++)
        {
            set<vector<int>>Set;
            vector<int>arr;
            int count = 0;
            
            for (int i=0; i<nums.size(); i++)
            {
                if (i>=len)
                {
                    arr.erase(arr.begin());
                    if (nums[i-len]%p==0) count--;
                }
                
                arr.push_back(nums[i]);
                if (nums[i]%p==0) count++;
                
                if (i>=len-1)
                {
                    if (Set.find(arr)!=Set.end()) continue;
                    Set.insert(arr);
                    if (count<=k)
                        ret += 1;
                }
            }
        }
        
        return ret;        
    }
};
