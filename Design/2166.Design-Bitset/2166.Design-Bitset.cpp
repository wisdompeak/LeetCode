class Bitset {    
    int flips[100000];
    int m;
    int totalFlip = 0;
    int cnt = 0;
public:
    Bitset(int size) {        
        m = size;
        for (int i=0; i<m; i++)
            flips[i] = 0;
    }
    
    void fix(int idx) 
    {
        if ((flips[idx]+totalFlip)%2==0)
        {
            flips[idx] += 1;
            flips[idx] %= 2;            
            cnt++;
        }
    }
    
    void unfix(int idx) 
    {
        if ((flips[idx]+totalFlip)%2==1)
        {
            flips[idx] += 1;
            flips[idx] %= 2;            
            cnt--;
        }
    }
    
    void flip() 
    {
        totalFlip += 1;
        totalFlip %= 2;
        cnt = m - cnt;
    }
    
    bool all() 
    {
        return cnt == m;
    }
    
    bool one() 
    {
        return cnt >= 1;
    }
    
    int count() 
    {
        return cnt;
    }
    
    string toString() 
    {
        string s;
        for (int i=0; i<m; i++)
        {
            int t = (flips[i]+totalFlip)%2;            
            s += (t==1?"1":"0");
        }
            
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
