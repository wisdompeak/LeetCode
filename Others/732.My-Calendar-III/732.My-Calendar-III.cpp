class MyCalendarThree {
public:
    map<int,int>Map;
    
    MyCalendarThree() 
    {
        
    }
    
    int book(int start, int end) 
    {
        Map[start]+=1;
        Map[end]-=1;
        
        int count=0;
        int ret=0;
        for (auto& [t, diff]: Map)
        {
            count += diff;
            ret = max(ret, count);
        }
        return ret;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
