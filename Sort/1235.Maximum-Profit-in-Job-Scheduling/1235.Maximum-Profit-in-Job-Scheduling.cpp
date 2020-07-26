class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>>jobs;
        set<int>endTimes({0});
        for (int i=0; i<startTime.size(); i++)
        {
            jobs.push_back({endTime[i],startTime[i],profit[i]});
            endTimes.insert(endTime[i]);
        }
        sort(jobs.begin(), jobs.end());

        unordered_map<int,int>time2val;
        time2val[0] = 0;
        int curVal = 0;

        for (auto job: jobs)
        {
            int end = job[0];
            int start = job[1];
            int val = job[2];

            auto iter = endTimes.upper_bound(start);
            int lastEnd = *prev(iter,1);            
            time2val[end] = max(curVal, time2val[lastEnd]+val);

            curVal = time2val[end];
        }
        return curVal;
    }
};
