class MyCalendarTwo {
    vector<pair<int,int>>events;
public:
    MyCalendarTwo() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        vector<pair<int,int>>temp;
        for (int i=0; i<events.size(); i++)
        {
            if (!(events[i].second<=start || events[i].first>=end))
                temp.push_back(events[i]);
        }
        sort(temp.begin(),temp.end());
        
        for (int i=1; i<temp.size(); i++)
        {
            if (temp[i].first<temp[i-1].second)
                return false;
        }
        
        events.push_back({start,end});        

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
