class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>q;
        for (auto x: envelopes)
        {
            if (q.empty() || x[1]>q.back())
                q.push_back(x[1]);
            else
            {
                auto iter = lower_bound(q.begin(), q.end(), x[1]);
                *iter = x[1];
            }
        }
        return q.size();
    }
};
