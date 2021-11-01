class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);
        
        vector<pair<int,int>>dp; // {time, value}
        dp.push_back({events[0][1], events[0][2]});
        int rollingMax = events[0][2];
            
        int ret = events[0][2];
        
        for (int i=1; i<n; i++)
        {
            int a = events[i][0]-1, b = events[i][1], v = events[i][2];
            
            int lastMax = 0;
            auto iter = upper_bound(dp.begin(), dp.end(), make_pair(a, INT_MAX));
            if (iter!=dp.begin())
            {
                iter = prev(iter);
                lastMax = iter->second;
            }                        
            ret = max(ret, lastMax + v);
            
            rollingMax = max(rollingMax, v);
            dp.push_back({b, rollingMax});
        }
        
        return ret;        
    }
};
