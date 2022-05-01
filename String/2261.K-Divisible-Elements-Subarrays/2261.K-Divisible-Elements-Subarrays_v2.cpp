using ULL = unsigned long long;
class Solution {
    ULL power[215];
    ULL P = 211;
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        power[0] = 1;
        for (int i=1; i<=211; i++)
            power[i] = power[i-1]*P;
        
        int ret = 0;
        
        for (int len=1; len<=nums.size(); len++)
        {
            unordered_set<ULL>Set;
            ULL hash = 0;
            int count = 0;
            for (int i=0; i<nums.size(); i++)
            {
                if (i>=len)
                {
                    hash = hash - nums[i-len]*power[len-1];
                    if (nums[i-len]%p==0) count--;
                }
                
                hash = hash*P + nums[i];
                if (nums[i]%p==0) count++;
                
                if (i>=len-1)
                {
                    if (Set.find(hash)!=Set.end()) continue;
                    Set.insert(hash);
                    if (count<=k)
                        ret += 1;
                }
            }
        }
        
        return ret;        
    }
};
