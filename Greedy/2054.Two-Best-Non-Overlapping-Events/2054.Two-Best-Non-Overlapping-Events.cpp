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
        
        vector<int>rollingMax(n);
        int m = 0;
        for (int i=0; i<n; i++)
        {
            m = max(m, events[i][2]);
            rollingMax[i] = m;
        }
        
        vector<int>endTimes;
        int ret = 0;
        
        for (int i=0; i<n; i++)
        {
            int a = events[i][0]-1, b = events[i][1], v = events[i][2];
            ret = max(ret, v);
            
            auto iter = upper_bound(endTimes.begin(), endTimes.end(), a);
            if (iter!=endTimes.begin())
            {
                iter = prev(iter);
                int idx = iter - endTimes.begin();
                ret = max(ret, rollingMax[idx] + v);
            }
            
            endTimes.push_back(b);
        }
        
        return ret;        
    }
};
