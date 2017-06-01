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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        int start=newInterval.start;
        int end=newInterval.end;
        vector<Interval> results;
        
        int i;
        for (i=0; i<intervals.size(); i++)
        {
            if (intervals[i].end<start)
                results.push_back(intervals[i]);
            else if (intervals[i].start>end)
                break;
            else
            {
                start=min(start,intervals[i].start);
                end=max(end,intervals[i].end);
            }
        }
        results.push_back(Interval(start,end));
        for (;i<intervals.size(); i++)
            results.push_back(intervals[i]);
        
        return results;
    }
};
