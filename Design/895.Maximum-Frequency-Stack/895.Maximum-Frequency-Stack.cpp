class FreqStack {
    unordered_map<int, vector<int>> freq2nums;  // freq -> a series of nums
    unordered_map<int, int> count; // num -> freq
    int maxFreq = 0;
    
public:
    FreqStack() {
        
    }
    
    void push(int x) 
    {
        int freq = count[x];
        
        freq2nums[freq+1].push_back(x);
        count[x] = freq+1;        
        maxFreq = max(maxFreq, freq+1);
    }
    
    int pop() 
    {
        int x = freq2nums[maxFreq].back();
        int freq = count[x];
        
        freq2nums[freq].pop_back();
        count[x] = freq-1;
        
        if (freq2nums[maxFreq].size()==0)
            maxFreq -= 1;
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
