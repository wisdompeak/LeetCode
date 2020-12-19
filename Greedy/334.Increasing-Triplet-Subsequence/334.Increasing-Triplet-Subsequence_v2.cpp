class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        vector<int>q;
        for (auto x: nums)
        {
            if (q.empty() || q.back()<x)
                q.push_back(x);
            else
            {
                auto iter = lower_bound(q.begin(), q.end(), x);
                *iter = x;
            }
            if (q.size()==3)
                return true;
        }
        return false;
    }
};
