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
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        vector<pair<int,int>>q;
        for (int i=0; i<intervals.size(); i++)
        {
            q.push_back({intervals[i].start,1});
            q.push_back({intervals[i].end,-1});
        }
        
        sort(q.begin(),q.end());
        
        int count = 0;
        for (int i=0; i<q.size(); i++)
        {
            count+=q[i].second;
            if (count>1) return false;
        }
        return true;
            
    }
};
