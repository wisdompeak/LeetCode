class ProductOfNumbers {
    vector<int>pre;
    int cur;
    int id;
    int lastZero = 0;
public:
    ProductOfNumbers() 
    {
        id = 0;
        cur = 1;        
        pre.push_back(cur);
    }
    
    void add(int num) 
    {   
        id++;     
        if (num!=0)
            cur *= num;
        else
        {
            cur = 1;
            lastZero = id;
        }
            
        pre.push_back(cur);
        
    }
    
    int getProduct(int k) 
    {
        if (lastZero <= id-k)
            return pre[id]/pre[id-k];
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
