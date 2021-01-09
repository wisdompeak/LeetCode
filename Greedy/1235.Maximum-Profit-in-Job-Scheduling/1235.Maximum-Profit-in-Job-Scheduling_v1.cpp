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
        map<int,int>dp;
        dp[-1] = 0;

        int ret = 0;
        for (int i=0; i<n; i++)
        {            
            int ans = ret;
            auto iter = dp.upper_bound(jobs[i][0]);
            ans = max(ans, prev(iter,1)->second + jobs[i][2]);
            dp[jobs[i][1]] = ans;

            ret = max(ret, ans);
        }

        return ret;
    }
};
