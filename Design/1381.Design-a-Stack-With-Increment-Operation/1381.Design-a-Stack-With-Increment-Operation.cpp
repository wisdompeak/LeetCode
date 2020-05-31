class CustomStack {
    vector<int>nums;
    vector<int>offset;
    int maxSize;
    int count = 0;
    int diff = 0;
public:
    CustomStack(int maxSize) 
    {
        this->maxSize =  maxSize;
        nums.resize(maxSize, 0);
        offset.resize(maxSize, 0);
    }
    
    void push(int x) 
    {
        if (count==maxSize) return;
        
        if (count>=1)
            offset[count-1] += diff;
        diff = 0;
        
        nums[count] = x;
        offset[count] = 0;
        count++;        
    }
    
    int pop() 
    {
        if (count==0) return -1;
        
        diff += offset[count-1];
        int ret = nums[count-1] + diff;
        count -= 1;
        return ret;        
    }
    
    void increment(int k, int val) 
    {
        if (count == 0) return;
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
