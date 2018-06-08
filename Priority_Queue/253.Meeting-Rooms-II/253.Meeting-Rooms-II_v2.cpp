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
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp1);
        multiset<int>Set;
        int count=0;
        int i=0;
        while (i<intervals.size())
        {            
            while (Set.size()==0 || i<intervals.size() && *Set.begin()>intervals[i].start)    
            {
                Set.insert(intervals[i].end);
                count = max(count,int(Set.size()));
                i++;                                
            }                                    
            Set.erase(Set.begin());                                     
        }
        return count;
    }
};
