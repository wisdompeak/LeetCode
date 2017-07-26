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
    set<int>Set;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) 
    {
        Set.insert(val);
    }
    
    vector<Interval> getIntervals() 
    {
        vector<Interval>result;
        int start;
        int end;
        int first=1;

        for (auto a:Set)
        {
            if (first)
            {
                start=a;
                end=a;
                first=0;
                continue;
            }
            
            if (a==end+1)
            {
                end=a;
            }
            else
            {
                Interval newInterval(start,end);
                result.push_back(newInterval);
                start=a;
                end=a;
            }
        }
        
        Interval newInterval(start,end);
        result.push_back(newInterval);        
        
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
