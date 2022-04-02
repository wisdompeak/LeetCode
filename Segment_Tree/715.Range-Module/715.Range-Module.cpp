class RangeModule {
    map<int,int>Map;
public:
    RangeModule() 
    {
        Map.clear();
    }
    
    void addRange(int left, int right) 
    {       
        auto iter1 = Map.lower_bound(left);
        int leftboundary=left;
        if (iter1!=Map.begin() && prev(iter1,1)->second>=left)
            leftboundary = prev(iter1,1)->first;
                            
        auto iter2 = Map.upper_bound(right);
        int rightboundary = right;
        if (iter2!=Map.begin())
            rightboundary = max(right, prev(iter2,1)->second);
        
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
            start1 = prev(iter1)->first;
            end1 = left;
        }

        auto iter2 = Map.lower_bound(right);
        int start2 = 0, end2 = 0;
        if (iter2!=Map.begin() && prev(iter2)->first < right)
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
