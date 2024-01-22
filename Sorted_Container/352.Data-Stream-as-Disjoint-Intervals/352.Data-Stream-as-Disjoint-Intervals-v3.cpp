/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    map<int,int>Map;
    
    /** Initialize your data structure here. */
    SummaryRanges() 
    {
        Map[-2]=-2;
    }
    
    void addNum(int val) 
    {
        auto pos = Map.lower_bound(val);        

        if (pos!=Map.end() && pos->first==val) return;                        
        if (prev(pos,1)->second>=val) return;  // if val is already within an interval                                        
        
        if (prev(pos,1)->second==val-1)
            prev(pos,1)->second=val;   // if val is at the right boundary of the previous interval
        else        
            Map[val]=val;               // if val is not connected to the previous interval, create a new one
                
        pos = Map.upper_bound(val);        
        if (pos!=Map.end() && pos->first==prev(pos,1)->second+1) // if the new interval is conneted to the next interval
        {
            prev(pos,1)->second = pos->second;
            Map.erase(pos);
        }         
        
    }
    
    vector<Interval> getIntervals() 
    {
        vector<Interval>results;
        for (auto a:Map)
        {
            if (a.first!=-2)
                results.push_back(Interval(a.first,a.second));
        }
        return results;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
