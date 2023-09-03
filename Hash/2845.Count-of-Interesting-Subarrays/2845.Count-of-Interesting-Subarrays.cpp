using LL = long long;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        int n = nums.size();
        int count = 0;
        unordered_map<int,LL>Map;
        Map[0]+=1;
        LL ret = 0;
        
        for (int i=0; i<n; i++)
        {
            count += ((nums[i]%modulo)==k);
            int m = count % modulo;
            int kk = (m-k+modulo)%modulo;
            
            ret += Map[kk];
            Map[m] += 1;
        }
        
        return ret;
    }
};
