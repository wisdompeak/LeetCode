class CustomStack {    
    int count = 0;
    int maxSize;
    vector<int>offset;
    vector<int>nums;
    int diff = 0;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        nums.resize(maxSize,0);
        offset.resize(maxSize,0);
    }
    
    void push(int x) 
    {   
        if (count == maxSize) return;

        if (count>=1 && diff!=0)
            offset[count-1] += diff;
        
        nums[count] = x;
        count++;
        offset[count-1] = 0;
        diff = 0;                
    }
    
    int pop() 
    {
        if (count==0) return -1;

        diff += offset[count-1];
        int ret = nums[count-1]+diff;        
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
