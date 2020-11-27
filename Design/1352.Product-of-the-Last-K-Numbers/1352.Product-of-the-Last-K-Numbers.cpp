class ProductOfNumbers {
    vector<int>pre;
    int id;
    int lastZero = 0;
public:
    ProductOfNumbers() 
    {
        id = 0;        
        pre.push_back(1);
    }
    
    void add(int num) 
    {   
        id++;     
        if (num!=0)
        {
            pre.push_back(pre.back()*num);
        }
            
        else
        {
            pre.push_back(1);
            lastZero = id;
        }
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
