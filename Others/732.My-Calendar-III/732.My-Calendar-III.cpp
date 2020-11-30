class MyCalendarThree {
public:
    multiset<pair<int,int>>Set;
    
    MyCalendarThree() 
    {
        
    }
    
    int book(int start, int end) 
    {
        Set.insert({start,1});
        Set.insert({end,-1});
        
        int count=0;
        int result=0;
        for (auto a: Set)
        {
            count+=a.second;
            result = max(result,count);
        }
        return result;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
