class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<vector<int>>jobs;
        for (int i=0; i<n; i++)
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        sort(jobs.begin(), jobs.end(), cmp);
        vector<int>ends;
        unordered_map<int,int>Map;

        int ret = 0;
        for (int i=0; i<n; i++)
        {            
            int ans = ret;
            auto iter = upper_bound(ends.begin(), ends.end(), jobs[i][0]);
            if (iter != ends.begin())
            {
                iter = prev(iter,1);
                ans = max(ans, Map[*iter] + jobs[i][2]);
            }
            else
                ans = max(ans, jobs[i][2]);

            if (i==0 || jobs[i][1]!=jobs[i-1][1])
                ends.push_back(jobs[i][1]);
            Map[jobs[i][1]] = ans;

            ret = max(ret, ans);
        }

        return ret;
    }
};
