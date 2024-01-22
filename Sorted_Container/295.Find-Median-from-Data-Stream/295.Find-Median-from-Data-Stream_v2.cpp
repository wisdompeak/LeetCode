class MedianFinder {
public:
    /** initialize your data structure here. */
    double result;
    multiset<int>Set;
    multiset<int>::iterator iter;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        Set.insert(num);
        
        if (Set.size()==1)
        {
            iter = Set.begin();
            result = *iter;
            return;
        }
        
        if (Set.size()%2==1)    // OOXOOO
        {
            if (num>=*iter)
                iter = next(iter,1);
            result = *iter;
        }
        else    // OOXOO
        {
            if (num<*iter)
                iter = prev(iter,1);
            result = *iter*0.5 + *next(iter,1)*0.5;                
        }        
    }
    
    double findMedian() 
    {
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
