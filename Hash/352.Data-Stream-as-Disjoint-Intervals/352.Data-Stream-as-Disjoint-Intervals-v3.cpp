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
    map<int,int>Map;
public:
    /** Initialize your data structure here. */
    SummaryRanges() 
    {
        Map.clear();
    }
    
    void addNum(int val) 
    {
        if (Map.size()==0)
        {
            Map[val]=val;
            return;
        }            
        
        auto pos=Map.lower_bound(val);
        
        if (pos==Map.begin())
        {
            if (val+1 == pos->first)
            {
                int left=pos->first;
                int right=pos->second;
                Map.erase(left);
                Map[val]=right;
            }
            else if (val+1<pos->first)
                Map[val]=val;            
        }
        else if (pos==Map.end())
        {
            auto pos1=prev(pos,1);
            int left=pos1->first;
            int right=pos1->second;
            if (right+1==val)
                Map[left]=val;
            else if (right+1<val)
                Map[val]=val;            
        }
        else
        {
            int flag1=0,flag2=0;
            
            auto pos1=prev(pos,1);
            int left=pos1->first;
            int right=pos1->second;
            if (right>=val)
                return;
            else if (right+1==val)
            {
                Map[left]=val;
                flag1=1;
            }
            
            auto pos2=pos;
            left=pos2->first;
            right=pos2->second;
            if (left==val)
                return;
            else if (left==val+1)
            {
                Map.erase(left);
                Map[val]=right;
                flag2=1;
            }
            
            if (flag1 && flag2)
            {
                auto pos = Map.lower_bound(val);
                prev(pos,1)->second=pos->second;
                Map.erase(pos);
            }
            else if (!flag1 && !flag2)
                Map[val]=val; 
        }
    }
    
    vector<Interval> getIntervals() 
    {
        vector<Interval>results;
        for (auto a:Map)        
            results.push_back(Interval(a.first,a.second));
        return results;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
