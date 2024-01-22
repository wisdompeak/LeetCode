class MedianFinder {
    multiset<int>Small;
    multiset<int>Large;
    
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        Small.clear();
        Large.clear();
    }
    
    void addNum(int num) 
    {
        if (Large.size()==0)
            Large.insert(num);
        else
        {
            if (num>=*(Large.begin()))
                Large.insert(num);
            else
                Small.insert(num);
        }
        
        if (Large.size()>=Small.size()+2)
        {
            Small.insert(*Large.begin());
            Large.erase(Large.begin());
        }
        else if (Small.size()>Large.size())
        {
            Large.insert(*(--Small.end()));
            Small.erase(--Small.end());
        }
    }
    
    double findMedian() 
    {
        if (Large.size()>Small.size())
            return *Large.begin();
        else
            return (*Large.begin()+*(--Small.end()))*1.0/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
