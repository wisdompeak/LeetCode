class FrontMiddleBackQueue {
    vector<int>q;
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) 
    {
        q.insert(q.begin(),val);
    }
    
    void pushMiddle(int val) 
    {
        q.insert(q.begin()+q.size()/2, val);
    }
    
    void pushBack(int val) 
    {
        q.push_back(val);
    }
    
    int popFront() 
    {
        if (q.empty()) return -1;
        int ret = q.front();
        q.erase(q.begin());
        return ret;
    }
    
    int popMiddle() 
    {
        if (q.empty()) return -1;
        int ret = *(q.begin()+(q.size()-1)/2);
        q.erase(q.begin()+(q.size()-1)/2);
        return ret;
    }
    
    int popBack() 
    {
        if (q.empty()) return -1;
        int ret = q.back();
        q.pop_back();
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
