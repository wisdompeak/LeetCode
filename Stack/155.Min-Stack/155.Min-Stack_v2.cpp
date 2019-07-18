class MinStack {
    stack<long long>Stack;
    long long Min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (Stack.empty())
        {
            Stack.push(0);
            Min = x;
        }
        else
        {
            if (x>=Min)
                Stack.push(x-Min);
            else
            {
                Stack.push(x-Min);
                Min = x;
            }
        }
    }
    
    void pop() 
    {
        if (Stack.top()<0)
            Min = Min + (-Stack.top());   
        Stack.pop();
    }
    
    int top() {
        int ret;
        if (Stack.top()>=0)
            ret = Stack.top()+Min;                    
        else
            ret = Min;
        return ret;
    }
    
    int getMin() {
        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
