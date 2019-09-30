class DinnerPlates {
    unordered_map<int, vector<int>>Plate;
    int leftNotFull;
    int rightNotEmpty;
    int cap;
    
public:
    DinnerPlates(int capacity) {
        leftNotFull = 0;
        rightNotEmpty = -1;
        cap = capacity; 
    }
    
    void push(int val) {
        Plate[leftNotFull].push_back(val);
        while (Plate[leftNotFull].size()==cap)
            leftNotFull++;
        
        rightNotEmpty = max(rightNotEmpty, (Plate[leftNotFull].size()==0)?leftNotFull-1:leftNotFull);
    }
    
    int pop() {
        if (rightNotEmpty==-1)
            return -1;
        return popAtStack(rightNotEmpty);
    }
    
    int popAtStack(int index) {
        if (Plate[index].size()==0)
            return -1;
        
        int ret = Plate[index].back();
        Plate[index].pop_back();
        
        if (index==rightNotEmpty && Plate[rightNotEmpty].size()==0)
        {
            while (Plate[rightNotEmpty].size()==0 && rightNotEmpty>=0)
                rightNotEmpty--;
        }
        
        leftNotFull = min(leftNotFull, index);
        
        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */


    
