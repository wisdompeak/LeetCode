/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if (a.first!=b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) 
    {
        vector<pair<int,int>>diff;
        for (int i=0; i<schedule.size(); i++)
        {
            for (auto range: schedule[i])
            {
                diff.push_back({range.start, +1});
                diff.push_back({range.end, -1});                                
            }
        }
        
        sort(diff.begin(),diff.end(), cmp);
        
        int count = 0;        
        vector<Interval>rets;
        int start = -1, end = -1;
                        
        for (auto d: diff)
        {
            count += d.second;
            if (d.second==-1 && count==0)
                start = d.first;
            else if (d.second==1 && count==1 && start!=-1)
            {
                end = d.first;
                rets.push_back({start,end});
            }                
        }
        
        return rets;
    }
};
