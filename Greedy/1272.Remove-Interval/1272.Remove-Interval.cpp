class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) 
    {
        vector<vector<int>>rets;
        for (auto v: intervals)
        {
            if (v[1]<=toBeRemoved[0] || v[0]>=toBeRemoved[1])
                rets.push_back(v);
            else
            {
                if (v[0] < toBeRemoved[0])
                    rets.push_back({v[0], min(v[1], toBeRemoved[0])});
                if (v[1] > toBeRemoved[1])
                    rets.push_back({max(v[0], toBeRemoved[1]), v[1]});
            }
        }
        return rets;
    }
};
