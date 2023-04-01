using LL = long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) 
    {
        unordered_map<int, LL>Map; 
        // Map[state] : how many times of state there have been
        Map[0] = 1;

        int state = 0;
        LL ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            state = state ^ nums[i];
            ret += Map[state];
            Map[state] += 1;
        }

        return ret;        
    }
};
