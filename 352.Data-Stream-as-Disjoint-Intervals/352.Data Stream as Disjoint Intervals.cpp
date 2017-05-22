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
    struct cmp
    {
        bool operator()(Interval a, Interval b)
        {
            return a.start<b.end;
        }
    };
    set<Interval,cmp>Set;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) 
    {
        int flag=0;
        int a,b;
        
        // 空集特殊处理
        if (Set.size()==0)
        {
            Set.insert(Interval(val,val));
            return;
        }
        
        
        // 如果已经存在于已有的区间中，那么什么都不用做
        auto it = Set.lower_bound(Interval(val,val));            
        if (val>=it->start && val<=it->end)
            return;        
        
        if (it!=Set.begin())
        {
            it--;
            if (val>=it->start && val<=it->end)
                return;
        }
            
        // 如果可以与一个区间相接，那么更新那个区间
        it = Set.lower_bound(Interval(val,val));
        if (it!=Set.begin())
        {
            it--;
            if (it->end==val-1)
            {
                a = it->start;
                b = val;
                Set.erase(it);
                Set.insert(Interval(a,b));
                flag=1;
            }
        }
        

        it = Set.lower_bound(Interval(val,val));
        if (it!=Set.end() && it->start==val+1)
        {
            a = val;
            b = it->end;
            Set.erase(it);
            Set.insert(Interval(a,b));
            flag++;
        }
        
        // 如果更新了两个区间，说明这两个区间可以拼接起来。
        if (flag==2)
        {
            it = Set.lower_bound(Interval(val,val));
            if (it!=Set.begin() && it!=Set.end())
            {
                auto it0=it;
                it0--;
                if (it0->end==it->start)
                {
                    a=it0->start;
                    b=it->end;
                    Set.erase(it0);
                    Set.erase(it);
                    Set.insert(Interval(a,b));
                }
            }
        }
        // 没有相邻接的区间可以更新，那么就自己单独作为一个区间
        else if (flag==0)
        {
            Set.insert(Interval(val,val));
        }
        
        
    }
    
    vector<Interval> getIntervals() 
    {
        vector<Interval>results;
        for (auto a:Set)
            results.push_back(a);
        return results;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
