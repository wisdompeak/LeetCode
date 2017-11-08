class MaxStack {
    list<int>List;
    map<int,vector<list<int>::iterator>>Map;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) 
    {
        List.push_back(x);
        Map[x].push_back(--List.end());
    }
    
    int pop() 
    {
        int x=List.back();
        Map[x].pop_back();
        if (Map[x].size()==0)
            Map.erase(x);
        List.pop_back();
        return x;
    }
    
    int top() 
    {
        return List.back();
    }
    
    int peekMax() 
    {
        return (--Map.end())->first;
    }
    
    int popMax() 
    {
        int x=(--Map.end())->first;
        auto it=Map[x].back();
        Map[x].pop_back();
        if (Map[x].size()==0)
            Map.erase(x);
        List.erase(it);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
