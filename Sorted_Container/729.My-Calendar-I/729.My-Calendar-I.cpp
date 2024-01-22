class MyCalendar {
    map<int,int>Map;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        auto iter1 = Map.upper_bound(start);
        if (iter1!=Map.begin())
        {
            auto iter2 = prev(iter1,1);
            if (iter2->second > start)
                return false;
        }
        if (iter1 != Map.end())
        {
            if (iter1->first < end)
                return false;
        }
        Map[start] = end;
        return true;
    }
};
