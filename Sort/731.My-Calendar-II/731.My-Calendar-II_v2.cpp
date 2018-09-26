class MyCalendarTwo {
    multiset<pair<int,int>>Set;
public:
    MyCalendarTwo() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        vector<pair<int,int>>p;
        for (auto x: Set)
        {
            if (!(end<=x.first || start>=x.second))
                p.push_back(x);
            if (end<=x.first) break;
        }        
        for (int i=1; i<p.size(); i++)
        {
            if (p[i].first<p[i-1].second)
                return false;
        }
        Set.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
