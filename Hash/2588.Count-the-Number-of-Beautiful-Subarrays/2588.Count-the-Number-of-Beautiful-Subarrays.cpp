class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) 
    {
        unordered_map<int,long long>Map;
        Map[0] = 1;
        int state = 0;
        long long ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            for (int k=0; k<31; k++)
            {
                int t = ((x>>k)&1) + ((state>>k)&1); 
                t = t%2;
                state = state - (((state>>k)&1)<<k) + (t<<k);
            }
            ret += Map[state];
            Map[state] += 1;            
        }
        
        return ret;
        
    }
};
