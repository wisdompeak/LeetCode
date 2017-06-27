class MyQueue {
    stack<int>Stack1;
    stack<int>Stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        Stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        while (Stack1.size()>1)
        {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        int result = Stack1.top();
        Stack1.pop();
        while (Stack2.size()>0)
        {
            Stack1.push(Stack2.top());
            Stack2.pop();
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() 
    {
        while (Stack1.size()>1)
        {
            Stack2.push(Stack1.top());
            Stack1.pop();
        }
        int result = Stack1.top();
        while (Stack2.size()>0)
        {
            Stack1.push(Stack2.top());
            Stack2.pop();
        }    
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return Stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
