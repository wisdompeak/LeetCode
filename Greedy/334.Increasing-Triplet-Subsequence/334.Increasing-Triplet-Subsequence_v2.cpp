class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        vector<int>q;
        for (auto x:nums)
        {
            auto pos=lower_bound(q.begin(),q.end(),x);
            if (pos==q.end())
                q.push_back(x);
            else
                *pos=x;            
            if (q.size()==3) return true;
        }
        return false;
    }
};
