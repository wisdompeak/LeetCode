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
    static bool cmp1(Interval a, Interval b)
    {
        return a.start<b.start;
    }
    struct cmp2
    {
        bool operator()(Interval a, Interval b)
        {
            return a.end>b.end;
        }            
    };
    
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp1);
        
        priority_queue<Interval,vector<Interval>,cmp2>pq;
        
        int count=0;
        int i=0;
        while (i<intervals.size())
        {
            while (pq.empty() || i<intervals.size() && pq.top().end>intervals[i].start)
            {
                pq.push(intervals[i]);
                i++;
            }                
            int n=pq.size();
            count=max(count,n);
            pq.pop();
        }
        return count;
    }
};
