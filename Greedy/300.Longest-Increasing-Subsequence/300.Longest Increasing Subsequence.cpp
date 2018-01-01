class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int>q;
        for (auto x:nums)
        {
            auto pos=lower_bound(q.begin(),q.end(),x);
            if (pos==q.end())
                q.push_back(x);
            else
                *pos=x;            
        }
        return q.size();               
    }
};
