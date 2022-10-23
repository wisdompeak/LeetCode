using LL = long long;
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {        
        vector<LL>odd1, odd2, even1, even2;
        for (auto x: nums)
        {
            if (x%2==0)
                even1.push_back(x);
            else
                odd1.push_back(x);
        }
        for (auto x: target)
        {
            if (x%2==0)
                even2.push_back(x);
            else
                odd2.push_back(x);
        }
        auto [ret1, buff1] = helper(even1, even2);
        auto [ret2, buff2] = helper(odd1, odd2);        
        return ret1 + ret2 - abs(buff1)/2;
    }
    
    pair<LL,LL> helper(vector<LL>&nums, vector<LL>&target)
    {
        sort(target.begin(), target.end());
        sort(nums.begin(), nums.end());
        
        LL buff = 0;
        LL ret = 0;
        for (int i=0; i<nums.size(); i++)
        {
            int x = target[i], y = nums[i];            
                
            LL diff = y - x;
            if (diff >= 0)
            {                
                if (buff < 0)
                    diff = max(0LL, diff + buff);
                ret += diff / 2;
            }
            else
            {                
                if (buff > 0)
                    diff = min(0LL, diff + buff);
                ret += abs(diff) / 2;                
            }
            buff += y-x;
        }
        
        return {ret, buff};        
    }
    
};
