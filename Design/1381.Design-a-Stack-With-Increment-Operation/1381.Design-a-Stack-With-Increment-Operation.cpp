class CustomStack {
    stack<int>Stack;
    int count = 0;
    int maxSize;
    vector<int>offset;
    int curoffset = 0;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        offset.resize(maxSize,0);
    }
    
    void push(int x) 
    {   
        if (count == maxSize) return;

        if (count>=1 && curoffset!=0)
            offset[count-1] += curoffset;
        
        Stack.push(x);
        count++;
        offset[count-1] = 0;
        curoffset = 0;                
    }
    
    int pop() 
    {
        if (Stack.empty()) return -1;

        curoffset += offset[count-1];
        int ret = Stack.top()+curoffset;
        Stack.pop();
        count--;
        return ret;
    }
    
    void increment(int k, int val) 
    {
        if (count==0) return;
        offset[min(k-1, count-1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
