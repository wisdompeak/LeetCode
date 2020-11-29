class FrontMiddleBackQueue {
    list<int> List;
    list<int>::iterator mid;
    int n = 0;
public:
    FrontMiddleBackQueue() {        
    }
    
    void pushFront(int val) 
    {                
        List.push_front(val);
        if (n==0)
            mid = List.begin();
        else if (n%2==1)
            mid = prev(mid);
        n++;
    }    

    void pushMiddle(int val) 
    {                
        if (n==0)
        {
            List.push_back(val);
            mid = List.begin();
        }            
        else if (n%2==0)
        {
            List.insert(next(mid), val);
            mid = next(mid);
        }
        else
        {
            List.insert(mid, val);
            mid = prev(mid);
        }
        n++;            
    }
    
    void pushBack(int val) 
    {
        List.push_back(val);        
        if (n==0)
            mid = List.begin();
        else if (n%2==0)
            mid = next(mid);
        n++;
    }
    
    int popFront() 
    {
        if (n==0) return -1;
        int ret = List.front();
        if (n%2==0)
            mid = next(mid);        
        List.pop_front();
        n--;            
        return ret;
    }
    
    int popMiddle() 
    {
        if (n==0) return -1;
        int ret = *mid;                     
        list<int>::iterator mid_new;
        if (n%2==1)        
            mid_new = prev(mid);                    
        else
            mid_new = next(mid);
        List.erase(mid);
        n--;   
        mid = mid_new;
        return ret;
    }
    
    int popBack() 
    {
        if (n==0) return -1;
        int ret = List.back();        
        if (n%2==1)
            mid = prev(mid);
        List.pop_back();
        n--;
        return ret;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
