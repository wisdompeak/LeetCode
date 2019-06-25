class MedianFinder {
    multiset<int>Set;
    multiset<int>::iterator it;
    double result;
    
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
    }
    
    void addNum(int num) 
    {
        Set.insert(num);
        
        if (Set.size()==1)
        {
            it = Set.begin();
            result = *it;
            return;
        }
        
        int N = Set.size();
        
        if (N%2==1)
        {
            if (num>=*it)
            {
                it = next(it,1);
                result = *it;
            }
            else
                result = *it;
        }
        else
        {
            if (num>=*it)
            {
                auto it2 = next(it,1);
                result = (*it+*it2)*1.0/2;
            }
            else
            {
                auto it2 = it;
                it = prev(it,1);
                result = (*it+*it2)*1.0/2;
            }
        }
    }
    
    double findMedian() 
    {        
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
