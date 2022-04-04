class RangeModule {
    map<int,int>Map;
public:
    RangeModule() {
    }
    
    void addRange(int left, int right) 
    {       
        int leftboundary=left;
        int rightboundary = right;

        auto iter1 = Map.lower_bound(left);
        if (iter1!=Map.begin() && prev(iter1)->second>=left)
        {
            iter1 = prev(iter1);
            leftboundary = iter1->first;
        }            
                            
        auto iter2 = Map.upper_bound(right);        
        if (iter2!=Map.begin() && prev(iter2)->second >= rightboundary)
            rightboundary = prev(iter2)->second;
        
        Map.erase(iter1,iter2);
        Map[leftboundary]=rightboundary;        
    }
    
    bool queryRange(int left, int right) 
    {
        auto iter = Map.upper_bound(left);
        return (iter!=Map.begin() && prev(iter)->second>=right);
    }
    
    void removeRange(int left, int right) 
    {
        auto iter1 = Map.lower_bound(left);
        int start1 = 0, end1 = 0;
        if (iter1!=Map.begin() && prev(iter1)->second > left)
        {
            iter1 = prev(iter1);
            start1 = iter1->first;
            end1 = left;
        }

        auto iter2 = Map.upper_bound(right);
        int start2 = 0, end2 = 0;
        if (iter2!=Map.begin() && prev(iter2)->second > right)
        {
            start2 = right;
            end2 = prev(iter2)->second;
        }

        Map.erase(iter1, iter2);
        if (start1 < end1) Map[start1] = end1;
        if (start2 < end2) Map[start2] = end2;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
