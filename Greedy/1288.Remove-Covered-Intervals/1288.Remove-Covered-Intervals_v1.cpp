class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if (a.first!=b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        vector<pair<int,int>>p;
        for (auto& interval: intervals)
        {
            p.push_back({interval[0],1});
            p.push_back({interval[1],-1});
        }
        sort(p.begin(), p.end(), cmp);
        int diff = 0;
        int ret = 0;
        for (auto x: p)
        {
            diff += x.second;
            if (x.second==-1 && diff == 0)
                ret++;
        }
        return ret;
    }
};
