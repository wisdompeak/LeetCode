class SegTreeNode
{
    public:
    SegTreeNode* left = NULL;
    SegTreeNode* right = NULL;
    int start, end;
    int info;  // the maximum value of the range
    bool tag; 
        
    SegTreeNode(int a, int b, int val)  // init for range [a,b] with val
    {                 
        tag = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val;
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = max(left->info, right->info);  // check with your own logic
        }        
    }    
    
    SegTreeNode(int a, int b, vector<int>& val)  // init for range [a,b] with the same-size array val
    {                 
        lazy_tag = 0;
        lazy_val = 0;
        start = a, end = b;
        if (a==b)
        {
            info = val[a];
            return;
        }        
        int mid = (a+b)/2;
        if (left==NULL)
        {
            left = new SegTreeNode(a, mid, val);
            right = new SegTreeNode(mid+1, b, val);            
            info = left->info + right->info;  // check with your own logic
        }        
    } 
    
    void pushDown()
    {
        if (tag==1 && left)
        {
            left->info = info;
            right->info = info;
            left->tag = 1;
            right->tag = 1;
            tag = 0;
        }        
    } 
    
    void updateRange(int a, int b, int val)     // set range [a,b] with val
    {        
        if (b < start || a > end ) // not covered by [a,b] at all
            return;        
        if (a <= start && end <=b)  // completely covered within [a,b]
        {
            info = val;
            tag = 1;
            return;
        }

        if (left)
        {
            pushDown();        
            left->updateRange(a, b, val);
            right->updateRange(a, b, val);
            info = max(left->info, right->info);  // write your own logic            
        }        
    }
    
    int queryRange(int a, int b)     // query the maximum value within range [a,b]
    {
        if (b < start || a > end )
        {
            return INT_MIN;  // check with your own logic
        }
        if (a <= start && end <=b)
        {
            return info;  // check with your own logic
        }          
        
        if (left)
        {
            pushDown();     
            int ret = max(left->queryRange(a, b), right->queryRange(a, b));        
            info = max(left->info, right->info);    // check with your own logic
            return ret;
        }
        
        return info;   // should not reach here
    }  

};

int main()
{
    SegTreeNode* root = new SegTreeNode(0, length-1, initVals);  // Set the leaf nodes with initVals.
  
    for (auto& update: updates)
    {
        int start = update[0], end = update[1], val = update[2];
        root->updateRange(start, end ,val); // set the range [start, end] with val 
    }
  
    vector<int>rets(length);
    for (int i=0; i<length; i++)
        rets[i] = root->queryRange(i, i); // get single node val
    return rets;
}
