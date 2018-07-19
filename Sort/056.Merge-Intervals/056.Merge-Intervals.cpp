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
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<pair<int,int>>q;
        for (int i=0; i<intervals.size(); i++)
        {
            q.push_back({intervals[i].start,-1});
            q.push_back({intervals[i].end,1});
        }
        
        sort(q.begin(),q.end());
        
        int count=0;
        int start, end;
        
        vector<Interval>results;
        
        for (int i=0; i<q.size(); i++)
        {            
            count+=-q[i].second;
            
            if (-q[i].second ==1 && count==1)
                start = q[i].first;
            else if (-q[i].second ==-1 && count==0)
            {
                end = q[i].first;
                results.push_back({start,end});
            }
        }
        
        return results;
    }
};
