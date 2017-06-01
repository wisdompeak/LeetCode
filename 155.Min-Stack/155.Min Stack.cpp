class MinStack {
    stack<int>Stack;
    stack<int>StackMin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) 
    {
        Stack.push(x);
        if (StackMin.empty())
            StackMin.push(x);
        else
            StackMin.push(min(x,StackMin.top()));
    }
    
    void pop() 
    {
        Stack.pop();
        StackMin.pop();
    }
    
    int top() 
    {
        return Stack.top();
    }
    
    int getMin() 
    {
        return StackMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
