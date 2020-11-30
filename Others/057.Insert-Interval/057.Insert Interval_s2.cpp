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
    struct cmp
    {
        bool operator()(Interval a,Interval b)
        {
            return a.start>b.start;
        }
    };
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        priority_queue<Interval,vector<Interval>,cmp>q;
        for (int i=0; i<intervals.size(); i++)
            q.push(intervals[i]);
        q.push(newInterval);
        
        vector<Interval>results;
        while (!q.empty())
        {
            Interval x = q.top();
            q.pop();
            if (q.empty())
            {
                results.push_back(x);
                break;
            }
            
            Interval y = q.top();
            if (x.end<y.start)
                results.push_back(x);
            else
            {
                q.pop();
                x.end=max(x.end,y.end);
                q.push(x);
            }
        }
        
        return results;
        
    }
};
