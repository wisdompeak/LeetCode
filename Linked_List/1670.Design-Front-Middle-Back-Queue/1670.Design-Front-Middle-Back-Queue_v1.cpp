class FrontMiddleBackQueue {
    int arr[1000];
    int n = 0;
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) 
    {
        for (int i=n; i>=1; i--)
            arr[i] = arr[i-1];
        arr[0] = val;
        n++;        
    }
    
    void pushMiddle(int val) 
    {
        int i = n-1;
        for (int i=n; i>= max(1,n/2); i--)
            arr[i] = arr[i-1];
        arr[n/2] = val;
        n++;        
    }
    
    void pushBack(int val) 
    {
        arr[n] = val;
        n++;        
    }
    
    int popFront() 
    {
        if (n==0) return -1;
        int ret = arr[0];
        for (int i=0; i<n-1; i++)
            arr[i] = arr[i+1];
        n--;        
        return ret;
    }
    
    int popMiddle() 
    {
        if (n==0) return -1;
        int ret = arr[(n-1)/2];
        for (int i=(n-1)/2; i<n; i++)
            arr[i] = arr[i+1];
        n--;        
        return ret;
    }
    
    int popBack() 
    {
        if (n==0) return -1;
        int ret = arr[n-1];
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
